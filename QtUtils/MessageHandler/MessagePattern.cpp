#include "MessagePattern.h"

namespace QtUtils
{
	namespace MessagePattern
	{
		QString MESSAGE_PATTERN = "[%{time yyyyMMdd h:mm:ss.zzz t} %{if-debug}D%{endif}%{if-info}I%{endif}%{if-warning}W%{endif}%{if-critical}C%{endif}%{if-fatal}F%{endif}] %{file}:%{line} - %{message}";;
	}
}

