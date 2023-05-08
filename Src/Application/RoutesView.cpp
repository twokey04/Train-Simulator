#include "RoutesView.h"

#include "IMainWindow.h"
#include "RoutesViewModel.h"

RoutesView::RoutesView( IMainWindow* parent )
    : BaseView( parent )
    , m_viewModel( nullptr )
{

}

IViewModel* RoutesView::GetViewModel()
{
    return m_viewModel;
}

void RoutesView::SetViewModel( IViewModel* viewModel )
{
    m_viewModel = static_cast<RoutesViewModel*>(viewModel);
}

void RoutesView::Render()
{
    switch ( m_viewModel->GetState() )
    {
    case ERoutesState::PoiSelection:
    {
        break;
    }
    case ERoutesState::RoutesComputing:
    {
        break;
    }
    case ERoutesState::RoutesComputed:
    {
        break;
    }
    case ERoutesState::RouteSimulation:
    {
        break;
    }
    }
}

void RoutesView::OnEvent( EVmEvent event )
{
    switch (event)
    {
    case EVmEvent::Generic_ChangedConnection:
        break;
    default:
        BaseView::OnEvent( event );
        break;
    }
}

