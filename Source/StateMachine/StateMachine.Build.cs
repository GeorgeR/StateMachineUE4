using UnrealBuildTool;

public class StateMachine : ModuleRules
{
	public StateMachine(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				"StateMachine/Public"
			});

		PrivateIncludePaths.AddRange(
			new string[] {
				"StateMachine/Private",
			});

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			    "CoreUObject",
			    "Engine",
            });

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate",
				"SlateCore",
			});

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			});
	}
}