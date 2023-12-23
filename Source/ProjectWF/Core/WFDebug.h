#pragma once

#include "CoreMinimal.h"

PROJECTWF_API DECLARE_LOG_CATEGORY_EXTERN(LogWF, Log, All)

#define WF_CUR_CLASS_FUNC (FString(__FUNCTION__))

#define WF_CUR_CLASS (FString(__FUNCTION__).Left(FString(__FUNCTION__).Find(TEXT(":"))))

#define WF_CUR_FUNC (FString(__FUNCTION__).Right(FString(__FUNCTION__).Len() - FString(__FUNCTION__).Find(TEXT("::")) - 2))

#define WF_CUR_LINE (FString::FromInt(__LINE__))

#define WF_CUR_CLASS_LINE (WF_CUR_CLASS + "(" + WF_CUR_LINE + ")")

#define WF_CUR_CLASS_FUNC_LINE (WF_CUR_CLASS_FUNC + "(" + WF_CUR_LINE + ")")

#if NO_LOGGING

#define WF_LOG(CategoryName, Format, ...)
#define WF_WARN(CategoryName, Format, ...)
#define WF_ERROR(CategoryName, Format, ...)
#define WF_LOG_S(Format, ...)
#define WF_WARN_S(Format, ...)
#define WF_ERROR_S(Format, ...)

#else

#define WF_LOG(CategoryName, Format, ...) \
	UE_LOG(CategoryName, Log, TEXT("%s: %s"), *WF_CUR_CLASS_FUNC_LINE, *FString::Printf(Format, ##__VA_ARGS__))

#define WF_WARN(CategoryName, Format, ...) \
	UE_LOG(CategoryName, Warning, TEXT("%s: %s"), *WF_CUR_CLASS_FUNC_LINE, *FString::Printf(Format, ##__VA_ARGS__))

#define WF_ERROR(CategoryName, Format, ...) \
	UE_LOG(CategoryName, Error, TEXT("%s: %s"), *WF_CUR_CLASS_FUNC_LINE, *FString::Printf(Format, ##__VA_ARGS__))

#define WF_LOG_S(Format, ...) \
	UE_LOG(LogWF, Log, TEXT("%s: %s"), *WF_CUR_CLASS_FUNC_LINE, *FString::Printf(Format, ##__VA_ARGS__))

#define WF_WARN_S(Format, ...) \
	UE_LOG(LogWF, Warning, TEXT("%s: %s"), *WF_CUR_CLASS_FUNC_LINE, *FString::Printf(Format, ##__VA_ARGS__))

#define WF_ERROR_S(Format, ...) \
	UE_LOG(LogWF, Error, TEXT("%s: %s"), *WF_CUR_CLASS_FUNC_LINE, *FString::Printf(Format, ##__VA_ARGS__))

#endif
