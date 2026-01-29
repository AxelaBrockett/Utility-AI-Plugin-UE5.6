// Some copyright should be here...

using UnrealBuildTool;

public class AxelaBrockettUtilityAIBase : ModuleRules
{
	public AxelaBrockettUtilityAIBase(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
            }
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"AIModule",
				"Core",
				"CoreUObject",
                "Engine",
				"GameplayDebugger",
				"NavigationSystem",
                "ZoneGraph",
                "ZoneGraphAnnotations"
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate",
				"SlateCore",
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

        SetupGameplayDebuggerSupport(Target);
    }
}
