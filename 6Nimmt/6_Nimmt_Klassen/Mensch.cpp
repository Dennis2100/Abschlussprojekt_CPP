#include "pch.h"
#include "Mensch.h"
#include "UI.h"

Mensch::Mensch()
{

}

Karte Mensch::GetHandkarteBeiIndex(int index)
{
	return handkarten[index];
}
