#pragma once

#include "BaseViewModel.h"

class StylesViewModel : public BaseViewModel
{
public:
    StylesViewModel(IMapService* styleService, INavigationService* navigationService, IViewModelListener* listener);

    void Init(const ViewModelInitParams& params) override;

    void UpdateMenuItems();

    IResourceRepository* GetResourceRepository();
    ITextureRepository* GetTextureRepository();
};
