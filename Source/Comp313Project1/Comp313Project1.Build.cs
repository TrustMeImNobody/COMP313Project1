// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Comp313Project1 : ModuleRules
{
	public Comp313Project1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
