#pragma once
#include "CoreMinimal.h"

PROJECTWF_API DECLARE_LOG_CATEGORY_EXTERN(LogWF, Log, All)
PROJECTWF_API DECLARE_LOG_CATEGORY_EXTERN(WarnWF, Warning, All)
PROJECTWF_API DECLARE_LOG_CATEGORY_EXTERN(ErrorWF, Error, All)

#define WF_CUR_CLASS_FUNC (FString(__FUNCTION__))

#define WF_CUR_CLASS (FString(__FUNCTION__).Left(FString(__FUNCTION__).Find(Text(":"))))

#define WF_CUR_FUNC (FString(__FUNCTION__).Right(FString(__FUNCTION__).Len() - FString(__FUNCTION__).Find(Text("::")) - 2))

#define WF_CUR_LINE (FString::FromInt(__LINE__))

#define WF_CUR_CLASS_LINE (WF_CUR_CLASS + "(" + WF_CUR_LINE + ")")

#define WF_CUR_CLASS_FUNC_LINE (WF_CUR_CLASS_FUNC + "(" + WF_CUR_LINE + ")")

#define WF_LOG(CategoryName, Format, ...) \
	UE_LOG(CategoryName, Log, TEXT("%s: %s"), *WF_CUR_CLASS_FUNC_LINE, *FString::Printf(Format, ##__VA_ARGS__))

#define WF_WARN(CategoryName, Format, ...) \
	UE_LOG(CategoryName, Warning, TEXT("%s: %s"), *WF_CUR_CLASS_FUNC_LINE, *FString::Printf(Format, ##__VA_ARGS__))

#define WF_ERROR(CategoryName, Format, ...) \
	UE_LOG(CategoryName, Error, TEXT("%s: %s"), *WF_CUR_CLASS_FUNC_LINE, *FString::Printf(Format, ##__VA_ARGS__))

#define WF_LOG_S(Format, ...) \
	WF_LOG(LogWF, Format, ##__VA_ARGS__)

#define WF_WARN_S(Format, ...) \
	WF_WARN(WarnWF, Format, ##__VA_ARGS__)

#define WF_ERROR_S(Format, ...) \
	WF_ERROR(ErrorWF, Format, ##__VA_ARGS__)


