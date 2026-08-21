#ifndef IMGUI_NOTIFY
#define IMGUI_NOTIFY

#pragma once

#define NOTIFY_MAX_MSG_LENGTH			4096
#define NOTIFY_PADDING_X				20.f
#define NOTIFY_PADDING_Y				20.f
#define NOTIFY_PADDING_MESSAGE_Y		10.f
#define NOTIFY_FADE_IN_OUT_TIME			150
#define NOTIFY_DEFAULT_DISMISS			3000
#define NOTIFY_OPACITY					1.0f
#define NOTIFY_TOAST_FLAGS				ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoFocusOnAppearing

#define NOTIFY_INLINE					inline
#define NOTIFY_NULL_OR_EMPTY(str)		(!str ||! strlen(str))
#define NOTIFY_FORMAT(fn, format, ...)	if (format) { va_list args; va_start(args, format); fn(format, args, ##__VA_ARGS__); va_end(args); }

typedef int ImGuiToastType;
typedef int ImGuiToastPhase;

enum ImGuiToastType_
{
	ImGuiToastType_None,
	ImGuiToastType_Success,
	ImGuiToastType_Warning,
	ImGuiToastType_Error,
	ImGuiToastType_Info,
	ImGuiToastType_COUNT
};

enum ImGuiToastPhase_
{
	ImGuiToastPhase_FadeIn,
	ImGuiToastPhase_Wait,
	ImGuiToastPhase_FadeOut,
	ImGuiToastPhase_Expired,
	ImGuiToastPhase_COUNT
};

class ImGuiToast
{
private:
	ImGuiToastType	type = ImGuiToastType_None;
	char			title[NOTIFY_MAX_MSG_LENGTH];
	char			content[NOTIFY_MAX_MSG_LENGTH];
	int				dismiss_time = NOTIFY_DEFAULT_DISMISS;
	uint64_t		creation_time = 0;

private:
	NOTIFY_INLINE auto set_title(const char* format, va_list args) { vsnprintf(this->title, sizeof(this->title), format, args); }
	NOTIFY_INLINE auto set_content(const char* format, va_list args) { vsnprintf(this->content, sizeof(this->content), format, args); }

public:
	NOTIFY_INLINE auto set_title(const char* format, ...) -> void { NOTIFY_FORMAT(this->set_title, format); }
	NOTIFY_INLINE auto set_content(const char* format, ...) -> void { NOTIFY_FORMAT(this->set_content, format); }
	NOTIFY_INLINE auto set_type(const ImGuiToastType& type) -> void { IM_ASSERT(type < ImGuiToastType_COUNT); this->type = type; };

public:
	NOTIFY_INLINE auto get_title() -> char* { return this->title; };

	NOTIFY_INLINE auto get_default_title() -> const char*
	{
		if (!strlen(this->title))
		{
			switch (this->type)
			{
			case ImGuiToastType_None:
				return NULL;
			case ImGuiToastType_Success:
				return "Success";
			case ImGuiToastType_Warning:
				return "Warning";
			case ImGuiToastType_Error:
				return "Error";
			case ImGuiToastType_Info:
				return "Info";
			default:
				return NULL;
			}
		}
		return this->title;
	};

	NOTIFY_INLINE auto get_type() -> const ImGuiToastType& { return this->type; };

	NOTIFY_INLINE auto get_color() -> const ImVec4
	{
		switch (this->type)
		{
		case ImGuiToastType_None:
			return { 255, 255, 255, 255 };
		case ImGuiToastType_Success:
			return { 0, 255, 0, 255 };
		case ImGuiToastType_Warning:
			return { 255, 255, 0, 255 };
		case ImGuiToastType_Error:
			return { 255, 0, 0, 255 };
		case ImGuiToastType_Info:
			return { 0, 157, 255, 255 };
		default:
			return { 255, 255, 255, 255 };
		}
	}

	NOTIFY_INLINE auto get_icon() -> const char*
	{
		switch (this->type)
		{
		case ImGuiToastType_None:
			return NULL;
		case ImGuiToastType_Success:
			return ICON_FA_CHECK_CIRCLE;
		case ImGuiToastType_Warning:
			return ICON_FA_EXCLAMATION_TRIANGLE;
		case ImGuiToastType_Error:
			return ICON_FA_TIMES_CIRCLE;
		case ImGuiToastType_Info:
			return ICON_FA_INFO_CIRCLE;
		default:
			return NULL;
		}
	}

	NOTIFY_INLINE auto get_content() -> char* { return this->content; };
	NOTIFY_INLINE auto get_elapsed_time() { return get_tick_count() - this->creation_time; }
	NOTIFY_INLINE auto get_dismiss_time() -> const int& { return this->dismiss_time; }

	NOTIFY_INLINE auto get_phase() -> const ImGuiToastPhase
	{
		const auto elapsed = get_elapsed_time();
		if (elapsed > NOTIFY_FADE_IN_OUT_TIME + this->dismiss_time + NOTIFY_FADE_IN_OUT_TIME)
			return ImGuiToastPhase_Expired;
		else if (elapsed > NOTIFY_FADE_IN_OUT_TIME + this->dismiss_time)
			return ImGuiToastPhase_FadeOut;
		else if (elapsed > NOTIFY_FADE_IN_OUT_TIME)
			return ImGuiToastPhase_Wait;
		else
			return ImGuiToastPhase_FadeIn;
	}

	NOTIFY_INLINE auto get_fade_percent() -> const float
	{
		const auto phase = get_phase();
		const auto elapsed = get_elapsed_time();
		if (phase == ImGuiToastPhase_FadeIn)
			return ((float)elapsed / (float)NOTIFY_FADE_IN_OUT_TIME) * NOTIFY_OPACITY;
		else if (phase == ImGuiToastPhase_FadeOut)
			return (1.f - (((float)elapsed - (float)NOTIFY_FADE_IN_OUT_TIME - (float)this->dismiss_time) / (float)NOTIFY_FADE_IN_OUT_TIME)) * NOTIFY_OPACITY;
		return 1.f * NOTIFY_OPACITY;
	}

	NOTIFY_INLINE static auto get_tick_count() -> const unsigned long long
	{
		using namespace std::chrono;
		return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
	}

public:
	ImGuiToast(ImGuiToastType type, int dismiss_time = NOTIFY_DEFAULT_DISMISS)
	{
		IM_ASSERT(type < ImGuiToastType_COUNT);
		this->type = type;
		this->dismiss_time = dismiss_time;
		this->creation_time = get_tick_count();
		memset(this->title, 0, sizeof(this->title));
		memset(this->content, 0, sizeof(this->content));
	}

	ImGuiToast(ImGuiToastType type, const char* format, ...) : ImGuiToast(type) { NOTIFY_FORMAT(this->set_content, format); }
	ImGuiToast(ImGuiToastType type, int dismiss_time, const char* format, ...) : ImGuiToast(type, dismiss_time) { NOTIFY_FORMAT(this->set_content, format); }
};

namespace ImGui
{
	NOTIFY_INLINE std::vector<ImGuiToast> notifications;

	NOTIFY_INLINE void InsertNotification(const ImGuiToast& toast)
	{
		notifications.push_back(toast);
	}

	NOTIFY_INLINE void RemoveNotification(int index)
	{
		notifications.erase(notifications.begin() + index);
	}

	NOTIFY_INLINE void RenderNotifications()
	{
		const auto vp_size = GetMainViewport()->Size;
		float height = 0.f;

		for (auto i = 0; i < notifications.size(); i++)
		{
			auto* current_toast = &notifications[i];
			if (current_toast->get_phase() == ImGuiToastPhase_Expired)
			{
				RemoveNotification(i);
				continue;
			}

			const auto icon = current_toast->get_icon();
			const auto title = current_toast->get_title();
			const auto content = current_toast->get_content();
			const auto default_title = current_toast->get_default_title();
			const auto opacity = current_toast->get_fade_percent();
			auto text_color = current_toast->get_color();
			text_color.w = opacity;

			char window_name[50]{};
			snprintf(window_name, sizeof(window_name), "##TOAST%d", i);

			SetNextWindowBgAlpha(opacity);
			SetNextWindowPos(ImVec2(vp_size.x - NOTIFY_PADDING_X, NOTIFY_PADDING_Y + height), ImGuiCond_Always, ImVec2(1.0f, 0.0f));
			Begin(window_name, NULL, NOTIFY_TOAST_FLAGS);

			PushTextWrapPos(vp_size.x / 3.f);
			bool was_title_rendered = false;

			if (!NOTIFY_NULL_OR_EMPTY(icon))
			{
				TextColored(text_color, icon);
				was_title_rendered = true;
			}

			if (!NOTIFY_NULL_OR_EMPTY(title))
			{
				if (!NOTIFY_NULL_OR_EMPTY(icon))
					SameLine();
				Text(title);
				was_title_rendered = true;
			}
			else if (!NOTIFY_NULL_OR_EMPTY(default_title))
			{
				if (!NOTIFY_NULL_OR_EMPTY(icon))
					SameLine();
				Text(default_title);
				was_title_rendered = true;
			}

			if (was_title_rendered && !NOTIFY_NULL_OR_EMPTY(content))
				SetCursorPosY(GetCursorPosY() + 5.f);

			if (!NOTIFY_NULL_OR_EMPTY(content))
			{
				if (was_title_rendered)
				{
					// Progress bar için zaman hesaplamaları
					const float elapsed = static_cast<float>(current_toast->get_elapsed_time());
					const float total_time = static_cast<float>(current_toast->get_dismiss_time());
					const float progress = 1.0f - (elapsed / total_time);
					
					// Arka plan rengi (22, 22, 22, 22)
					ImVec4 bg_color = ImVec4(22.0f/255.0f, 22.0f/255.0f, 22.0f/255.0f, 22.0f/255.0f);
					bg_color.w = opacity;
					
					// Bar pozisyonu ve boyutları
					ImVec2 bar_pos = GetCursorScreenPos();
					float bar_width = GetContentRegionAvail().x;
					float bar_height = 4.0f;
					
					// Arka plan bar'ı çiz
					ImGui::GetWindowDrawList()->AddRectFilled(
						bar_pos,
						ImVec2(bar_pos.x + bar_width, bar_pos.y + bar_height),
						ImGui::ColorConvertFloat4ToU32(bg_color)
					);
					
					// Rainbow renk geçişi (ters yönde)
					float hue = (1.0f - progress) * 1.0f;
					ImVec4 bar_color = ImColor::HSV(hue, 1.0f, 1.0f);
					bar_color.w = opacity;
					
					// İlerleme bar'ını çiz
					float progress_width = bar_width * progress;
					ImGui::GetWindowDrawList()->AddRectFilled(
						bar_pos,
						ImVec2(bar_pos.x + progress_width, bar_pos.y + bar_height),
						ImGui::ColorConvertFloat4ToU32(bar_color)
					);
					
					SetCursorPosY(GetCursorPosY() + 8.0f);
				}
				Text(content);
			}
			PopTextWrapPos();

			height += GetWindowHeight() + NOTIFY_PADDING_MESSAGE_Y;
			End();
		}
	}
}

#endif