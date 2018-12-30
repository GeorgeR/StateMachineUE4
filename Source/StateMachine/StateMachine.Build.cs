using UnrealBuildTool;

public class StateMachine : ModuleRules
{
	public StateMachine(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

	    if (Target.Version.MinorVersion <= 19)
	    {
            PublicIncludePaths.AddRange(
			    new string[] {
				    "Public"
			    });

		    PrivateIncludePaths.AddRange(
			    new string[] {
				    "Private",
			    });
        }

		PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
			    "CoreUObject"
            });

		PrivateDependencyModuleNames.AddRange(
			new string[] {
			});
	}
}