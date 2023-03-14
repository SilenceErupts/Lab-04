// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TopDownShmup/TopDownShmupPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTopDownShmupPlayerController() {}
// Cross Module References
	TOPDOWNSHMUP_API UClass* Z_Construct_UClass_ATopDownShmupPlayerController_NoRegister();
	TOPDOWNSHMUP_API UClass* Z_Construct_UClass_ATopDownShmupPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_TopDownShmup();
// End Cross Module References
	void ATopDownShmupPlayerController::StaticRegisterNativesATopDownShmupPlayerController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATopDownShmupPlayerController);
	UClass* Z_Construct_UClass_ATopDownShmupPlayerController_NoRegister()
	{
		return ATopDownShmupPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_ATopDownShmupPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATopDownShmupPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_TopDownShmup,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATopDownShmupPlayerController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "TopDownShmupPlayerController.h" },
		{ "ModuleRelativePath", "TopDownShmupPlayerController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATopDownShmupPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATopDownShmupPlayerController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATopDownShmupPlayerController_Statics::ClassParams = {
		&ATopDownShmupPlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008002A4u,
		METADATA_PARAMS(Z_Construct_UClass_ATopDownShmupPlayerController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownShmupPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATopDownShmupPlayerController()
	{
		if (!Z_Registration_Info_UClass_ATopDownShmupPlayerController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATopDownShmupPlayerController.OuterSingleton, Z_Construct_UClass_ATopDownShmupPlayerController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATopDownShmupPlayerController.OuterSingleton;
	}
	template<> TOPDOWNSHMUP_API UClass* StaticClass<ATopDownShmupPlayerController>()
	{
		return ATopDownShmupPlayerController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATopDownShmupPlayerController);
	struct Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_TopDownShmupPlayerController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_TopDownShmupPlayerController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATopDownShmupPlayerController, ATopDownShmupPlayerController::StaticClass, TEXT("ATopDownShmupPlayerController"), &Z_Registration_Info_UClass_ATopDownShmupPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATopDownShmupPlayerController), 2713829167U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_TopDownShmupPlayerController_h_1354270300(TEXT("/Script/TopDownShmup"),
		Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_TopDownShmupPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_TopDownShmupPlayerController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
