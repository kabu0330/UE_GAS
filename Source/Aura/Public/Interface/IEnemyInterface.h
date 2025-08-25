// 

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IEnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UIEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API IIEnemyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;
};
