// Fill out your copyright notice in the Description page of Project Settings.


#include "BaoanchaxunAPI.h"

UBaoanchaxunAPI::UBaoanchaxunAPI() {

}

void UBaoanchaxunAPI::getDanrenxinxi(FString pid)
{
	TSharedRef<IHttpRequest> HttpReuest = FHttpModule::Get().CreateRequest();
	HttpReuest->SetURL("http://localhost:31111/zhsa/securityStaff/list?personId=" + pid);
	HttpReuest->SetVerb(TEXT("GET"));
	HttpReuest->SetHeader(TEXT("Content-Type"), TEXT("application/x-www-form-urlencoded"));
	HttpReuest->OnProcessRequestComplete().BindUObject(this, &UBaoanchaxunAPI::getDanrenxinxiResponse);
	HttpReuest->ProcessRequest();
}

void UBaoanchaxunAPI::getDanrenxinxiResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
	if (!HttpRequest.IsValid() || !HttpResponse.IsValid())
	{
		return;
	}
	else if (bSucceeded && EHttpResponseCodes::IsOk(HttpResponse->GetResponseCode()))
	{
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(HttpResponse->GetContentAsString());
		if (FJsonSerializer::Deserialize(Reader, JsonObject))
		{
			FString code = JsonObject->GetStringField("code");
			FString msg = JsonObject->GetStringField("msg");
			TSharedPtr<FJsonObject> single = JsonObject->GetObjectField("data");
			FString personId = single->GetStringField("personId");
			FString personFaceImage = single->GetStringField("personFaceImage");
			FString personName = single->GetStringField("personName");
			FString zoneName = single->GetStringField("zoneName");
			FString longitude = single->GetStringField("longitude");
			FString latitude = single->GetStringField("latitude");
			FUDanrenxinxi data = FUDanrenxinxi(personId, personFaceImage, personName, zoneName, longitude, latitude);
			UE_LOG(LogTemp, Warning, TEXT("%s"), *(code));
		}
	}
}