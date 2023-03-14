// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TopDownShmup/AssaultWeapon.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAssaultWeapon() {}
// Cross Module References
	TOPDOWNSHMUP_API UClass* Z_Construct_UClass_AAssaultWeapon_NoRegister();
	TOPDOWNSHMUP_API UClass* Z_Construct_UClass_AAssaultWeapon();
	TOPDOWNSHMUP_API UClass* Z_Construct_UClass_AWeapon();
	UPackage* Z_Construct_UPackage__Script_TopDownShmup();
// End Cross Module References
	void AAssaultWeapon::StaticRegisterNativesAAssaultWeapon()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAssaultWeapon);
	UClass* Z_Construct_UClass_AAssaultWeapon_NoRegister()
	{
		return AAssaultWeapon::StaticClass();
	}
	struct Z_Construct_UClass_AAssaultWeapon_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAssaultWeapon_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AWeapon,
		(UObject* (*)())Z_Construct_UPackage__Script_TopDownShmup,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAssaultWeapon_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "AssaultWeapon.h" },
		{ "ModuleRelativePath", "AssaultWeapon.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAssaultWeapon_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAssaultWeapon>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AAssaultWeapon_Statics::ClassParams = {
		&AAssaultWeapon::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AAssaultWeapon_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAssaultWeapon_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAssaultWeapon()
	{
		if (!Z_Registration_Info_UClass_AAssaultWeapon.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAssaultWeapon.OuterSingleton, Z_Construct_UClass_AAssaultWeapon_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AAssaultWeapon.OuterSingleton;
	}
	template<> TOPDOWNSHMUP_API UClass* StaticClass<AAssaultWeapon>()
	{
		return AAssaultWeapon::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAssaultWeapon);
	struct Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_AssaultWeapon_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_AssaultWeapon_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AAssaultWeapon, AAssaultWeapon::StaticClass, TEXT("AAssaultWeapon"), &Z_Registration_Info_UClass_AAssaultWeapon, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAssaultWeapon), 3896737598U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_AssaultWeapon_h_4151207179(TEXT("/Script/TopDownShmup"),
		Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_AssaultWeapon_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_AssaultWeapon_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
