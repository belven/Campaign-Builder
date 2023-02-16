#pragma once
#if WITH_EDITOR

#include "IDetailCustomization.h"

class FQuestDetails : public IDetailCustomization
{
public:
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
	static TSharedRef<IDetailCustomization> MakeInstance();
};

#endif