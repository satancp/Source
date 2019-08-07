// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Http.h"
#include "Json.h"
#include "UObject/NoExportTypes.h"
#include "BaoanchaxunAPI.generated.h"

/**
 * 
 */
UCLASS()
class ZHIHUI_API UBaoanchaxunAPI : public UObject
{
	GENERATED_BODY()
public:
	UBaoanchaxunAPI();
	UFUNCTION(BlueprintCallable)
		void getDanrenxinxi(FString pid);
	void getDanrenxinxiResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);
	UFUNCTION(BlueprintCallable)
		void getQuanbuxinxi();
	void getQuanbuxinxiResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);
	UFUNCTION(BlueprintCallable)
		void getXingdongguiji(FString pid);
	void getXingdongguijiResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);
	UFUNCTION(BlueprintCallable)
		void getFujinbaoan(FString ecode);
	void getFujinbaoanResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);
	UFUNCTION(BlueprintCallable)
		void getPaifabaoan(FString ecode);
	void getPaifabaoanResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);
};

USTRUCT()
struct FUDanrenxinxi {
	GENERATED_BODY()
		UPROPERTY() FString personId;
	UPROPERTY() FString personFaceImage;
	UPROPERTY() FString personName;
	UPROPERTY() FString zoneName;
	UPROPERTY() FString longitude;
	UPROPERTY() FString latitude;

	FUDanrenxinxi() {};
	FUDanrenxinxi(FString pid, FString pfi, FString pn, FString zn, FString lon, FString lat) {
		personId = pid;
		personFaceImage = pfi;
		personName = pn;
		zoneName = zn;
		longitude = lon;
		latitude = lat;
	};
};