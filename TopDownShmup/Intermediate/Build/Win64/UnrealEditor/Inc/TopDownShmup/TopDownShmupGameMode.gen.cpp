// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TopDownShmup/TopDownShmupGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTopDownShmupGameMode() {}
// Cross Module References
	TOPDOWNSHMUP_API UClass* Z_Construct_UClass_ATopDownShmupGameMode_NoRegister();
	TOPDOWNSHMUP_API UClass* Z_Construct_UClass_ATopDownShmupGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_TopDownShmup();
// End Cross Module References
	void ATopDownShmupGameMode::StaticRegisterNativesATopDownShmupGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATopDownShmupGameMode);
	UClass* Z_Construct_UClass_ATopDownShmupGameMode_NoRegister()
	{
		return ATopDownShmupGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ATopDownShmupGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATopDownShmupGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_TopDownShmup,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATopDownShmupGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "TopDownShmupGameMode.h" },
		{ "ModuleRelativePath", "TopDownShmupGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATopDownShmupGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATopDownShmupGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATopDownShmupGameMode_Statics::ClassParams = {
		&ATopDownShmupGameMode::StaticClass,
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
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ATopDownShmupGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownShmupGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATopDownShmupGameMode()
	{
		if (!Z_Registration_Info_UClass_ATopDownShmupGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATopDownShmupGameMode.OuterSingleton, Z_Construct_UClass_ATopDownShmupGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATopDownShmupGameMode.OuterSingleton;
	}
	template<> TOPDOWNSHMUP_API UClass* StaticClass<ATopDownShmupGameMode>()
	{
		return ATopDownShmupGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATopDownShmupGameMode);
	struct Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_TopDownShmupGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_TopDownShmupGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATopDownShmupGameMode, ATopDownShmupGameMode::StaticClass, TEXT("ATopDownShmupGameMode"), &Z_Registration_Info_UClass_ATopDownShmupGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATopDownShmupGameMode), 1814083581U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_TopDownShmupGameMode_h_1527175193(TEXT("/Script/TopDownShmup"),
		Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_TopDownShmupGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_TopDownShmupGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
