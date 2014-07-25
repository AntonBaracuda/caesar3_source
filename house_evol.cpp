#include "house_evol.h"
#include "defs.h"
#include "variables.h"

void __cdecl fun_decayService_culture()
{
  signed int i; // [sp+4Ch] [bp-4h]@1

  for ( i = 1; i < 2000; ++i )
  {
    if ( buildings[i].inUse == 1 )
    {
      if ( buildings[i].house_size )
      {
        if ( _LOBYTE(buildings[i].house_theater_amphi_wine) <= 1 )
          _LOBYTE(buildings[i].house_theater_amphi_wine) = 0;
        else
          --_LOBYTE(buildings[i].house_theater_amphi_wine);

        if ( _HIBYTE(buildings[i].house_theater_amphi_wine) <= 1 )
          _HIBYTE(buildings[i].house_theater_amphi_wine) = 0;
        else
          --_HIBYTE(buildings[i].house_theater_amphi_wine);

        if ( _LOBYTE(buildings[i].house_amphiGlad_colo) <= 1 )
          _LOBYTE(buildings[i].house_amphiGlad_colo) = 0;
        else
          --_LOBYTE(buildings[i].house_amphiGlad_colo);

        if ( (signed int)_HIBYTE(buildings[i].house_amphiGlad_colo) <= 1 )
          _HIBYTE(buildings[i].house_amphiGlad_colo) = 0;
        else
          --_HIBYTE(buildings[i].house_amphiGlad_colo);

        if ( _LOBYTE(buildings[i].house_school_library) <= 1 )
          _LOBYTE(buildings[i].house_school_library) = 0;
        else
          --_LOBYTE(buildings[i].house_school_library);

        if ( (signed int)_HIBYTE(buildings[i].house_school_library) <= 1 )
          _HIBYTE(buildings[i].house_school_library) = 0;
        else
          --_HIBYTE(buildings[i].house_school_library);

        if ( _LOBYTE(buildings[i].house_school_library) <= 1 )
          _LOBYTE(buildings[i].house_school_library) = 0;
        else
          --_LOBYTE(buildings[i].house_school_library);

        if ( (signed int)_HIBYTE(buildings[i].house_school_library) <= 1 )
          _HIBYTE(buildings[i].house_school_library) = 0;
        else
          --_HIBYTE(buildings[i].house_school_library);

        if ( _LOBYTE(buildings[i].house_academy_barber) <= 1 )
          _LOBYTE(buildings[i].house_academy_barber) = 0;
        else
          --_LOBYTE(buildings[i].house_academy_barber);

        if ( (signed int)_HIBYTE(buildings[i].house_academy_barber) <= 1 )
          _HIBYTE(buildings[i].house_academy_barber) = 0;
        else
          --_HIBYTE(buildings[i].house_academy_barber);

        if ( (signed int)(unsigned char)building_64_house_clinic[128 * i] <= 1 )
          building_64_house_clinic[128 * i] = 0;
        else
          --building_64_house_clinic[128 * i];

        if ( buildings[i].house_bathhouse_dock_numships_entert_days <= 1 )
          buildings[i].house_bathhouse_dock_numships_entert_days = 0;
        else
          --buildings[i].house_bathhouse_dock_numships_entert_days;
        if ( (signed int)(unsigned char)building_66_house_hospital_entert_days2[128 * i] <= 1 )
          building_66_house_hospital_entert_days2[128 * i] = 0;
        else
          --building_66_house_hospital_entert_days2[128 * i];
        if ( (signed int)(unsigned char)building_67_house_ceres[128 * i] <= 1 )
          building_67_house_ceres[128 * i] = 0;
        else
          --building_67_house_ceres[128 * i];
        if ( (signed int)(unsigned char)building_68_house_neptune[128 * i] <= 1 )
          building_68_house_neptune[128 * i] = 0;
        else
          --building_68_house_neptune[128 * i];
        if ( (signed int)(unsigned char)building_69_house_mercury[128 * i] <= 1 )
          building_69_house_mercury[128 * i] = 0;
        else
          --building_69_house_mercury[128 * i];
        if ( (signed int)(unsigned char)building_6a_house_mars[128 * i] <= 1 )
          building_6a_house_mars[128 * i] = 0;
        else
          --building_6a_house_mars[128 * i];
        if ( (signed int)(unsigned char)building_6b_house_venus[128 * i] <= 1 )
          building_6b_house_venus[128 * i] = 0;
        else
          --building_6b_house_venus[128 * i];
      }
    }
  }
}

void fun_determineHouseEvolveText(int buildingId)
{
  int numFoods; // [sp+4Ch] [bp-50h]@6
  signed int i; // [sp+50h] [bp-4Ch]@6
  bool desirabilityMet; // [sp+54h] [bp-48h]@2
  signed int reqWine; // [sp+58h] [bp-44h]@6
  signed int v5; // [sp+58h] [bp-44h]@80
  int reqFoodTypes; // [sp+68h] [bp-34h]@6
  int v7; // [sp+68h] [bp-34h]@80
  signed int reqHealth; // [sp+6Ch] [bp-30h]@6
  signed int v9; // [sp+6Ch] [bp-30h]@80
  signed int reqReligion; // [sp+7Ch] [bp-20h]@6
  signed int v11; // [sp+7Ch] [bp-20h]@80
  signed int reqEducation; // [sp+80h] [bp-1Ch]@6
  signed int v13; // [sp+80h] [bp-1Ch]@80
  signed int reqEntertainment; // [sp+84h] [bp-18h]@6
  signed int v15; // [sp+84h] [bp-18h]@80
  int reqWater; // [sp+88h] [bp-14h]@6
  int v17; // [sp+88h] [bp-14h]@80
  int desirability; // [sp+8Ch] [bp-10h]@1
  signed int v19; // [sp+98h] [bp-4h]@1
  int v20; // [sp+98h] [bp-4h]@80

  v19 = buildings[buildingId].level_resourceId;
  desirability = building_7a_desirability[128 * buildingId];

  if ( desirability > model_houses[v19].des_devolve[0] )
    desirabilityMet = desirability >= model_houses[v19].des_evolve;
  else
    desirabilityMet = -1;

  reqWater = model_houses[v19].water;
  reqEntertainment = model_houses[v19].entertainment;
  reqEducation = model_houses[v19].education;
  reqReligion = model_houses[v19].religion;
  reqHealth = model_houses[v19].health;
  reqFoodTypes = model_houses[v19].foodtypes;
  reqWine = model_houses[v19].wine;
  numFoods = 0;
  for ( i = 0; i < 4; ++i )
  {
    if ( buildings[buildingId].grow_value_house_foodstocks[i] )
      ++numFoods;
  }
  if ( desirabilityMet == -1 )
  {
    _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 0;
    return;
  }
  if ( reqWater == 1 && !buildings[buildingId].hasFountain && !buildings[buildingId].house_hasWell )
  {
    _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 1;
    return;
  }
  if ( reqWater == 2 && !buildings[buildingId].hasFountain )
  {
    _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 2;
    return;
  }
  if ( reqEntertainment <= building_6e_house_entertainment[128 * buildingId] )
  {
    if ( reqFoodTypes > numFoods )
    {
      if ( reqFoodTypes == 1 )
      {
        _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 9;
        return;
      }
      if ( reqFoodTypes == 2 )
      {
        _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 10;
        return;
      }
      if ( reqFoodTypes == 3 )
      {
        _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 11;
        return;
      }
    }
    if ( reqEducation > building_6f_house_education[128 * buildingId] )
    {
      if ( reqEducation == 1 )
      {
        _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 14;
        return;
      }
      if ( reqEducation == 2 )
      {
        if ( _LOBYTE(buildings[buildingId].house_school_library) )
        {
          _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 15;
          return;
        }
        if ( _HIBYTE(buildings[buildingId].house_school_library) )
        {
          _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 16;
          return;
        }
      }
      else
      {
        if ( reqEducation == 3 )
        {
          _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 17;
          return;
        }
      }
    }
    if ( model_houses[v19].bathhouse > buildings[buildingId].house_bathhouse_dock_numships_entert_days )
    {
      _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 18;
      return;
    }
    if ( model_houses[v19].pottery > buildings[buildingId].house_pottery )
    {
      _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 19;
      return;
    }
    if ( reqReligion > building_71_house_numGods[128 * buildingId] )
    {
      if ( reqReligion == 1 )
      {
        _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 20;
        return;
      }
      if ( reqReligion == 2 )
      {
        _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 21;
        return;
      }
      if ( reqReligion == 3 )
      {
        _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 22;
        return;
      }
    }
    if ( model_houses[v19].barber > _HIBYTE(buildings[buildingId].house_academy_barber) )
    {
      _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 23;
      return;
    }
    if ( reqHealth <= building_70_house_health[128 * buildingId] )
    {
      if ( model_houses[v19].oil > buildings[buildingId].house_oil )
      {
        _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 27;
        return;
      }
      if ( model_houses[v19].furniture > buildings[buildingId].house_furniture )
      {
        _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 28;
        return;
      }
      if ( reqWine > buildings[buildingId].house_wine )
      {
        _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 29;
        return;
      }
      if ( reqWine > 1 && city_inform[ciid].numWineTypesAvailable[0] < 2 )
      {
        _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 65;
        return;
      }
      if ( v19 >= 19 )
      {
        _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 60;
        return;
      }
      v20 = v19 + 1;
      v17 = model_houses[v20].water;
      v15 = model_houses[v20].entertainment;
      v13 = model_houses[v20].education;
      v11 = model_houses[v20].religion;
      v9 = model_houses[v20].health;
      v7 = model_houses[v20].foodtypes;
      v5 = model_houses[v20].wine;
      if ( desirabilityMet )
      {
        if ( v17 == 1
          && !buildings[buildingId].hasFountain
          && !buildings[buildingId].house_hasWell )
        {
          _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 31;
          return;
        }
        if ( v17 == 2 && !buildings[buildingId].hasFountain )
        {
          _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 32;
          return;
        }
        if ( v15 <= building_6e_house_entertainment[128 * buildingId] )
        {
          if ( v7 > numFoods )
          {
            if ( v7 == 1 )
            {
              _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 39;
              return;
            }
            if ( v7 == 2 )
            {
              _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 40;
              return;
            }
            if ( v7 == 3 )
            {
              _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 41;
              return;
            }
          }
          if ( v13 > building_6f_house_education[128 * buildingId] )
          {
            if ( v13 == 1 )
            {
              _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 44;
              return;
            }
            if ( v13 == 2 )
            {
              if ( _LOBYTE(buildings[buildingId].house_school_library) )
              {
                _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 45;
                return;
              }
              if ( _HIBYTE(buildings[buildingId].house_school_library) )
              {
                _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 46;
                return;
              }
            }
            else
            {
              if ( v13 == 3 )
              {
                _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 47;
                return;
              }
            }
          }
          if ( model_houses[v20].bathhouse > buildings[buildingId].house_bathhouse_dock_numships_entert_days )
          {
            _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 48;
            return;
          }
          if ( model_houses[v20].pottery > buildings[buildingId].house_pottery )
          {
            _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 49;
            return;
          }
          if ( v11 <= building_71_house_numGods[128 * buildingId] )
            goto LABEL_154;
          if ( v11 == 1 )
          {
            _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 50;
            return;
          }
          if ( v11 == 2 )
          {
            _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 51;
            return;
          }
          if ( v11 != 3 )
          {
LABEL_154:
            if ( model_houses[v20].barber <= _HIBYTE(buildings[buildingId].house_academy_barber) )
            {
              if ( v9 <= building_70_house_health[128 * buildingId] )
              {
                if ( model_houses[v20].oil <= buildings[buildingId].house_oil )
                {
                  if ( model_houses[v20].furniture <= buildings[buildingId].house_furniture )
                  {
                    if ( v5 <= buildings[buildingId].house_wine )
                    {
                      if ( v5 <= 1 || city_inform[ciid].numWineTypesAvailable[0] >= 2 )
                      {
                        _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 61;
                        if ( _LOBYTE(buildings[buildingId].word_94BDAC[0]) == 1 )
                        {
                          _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 64;
                        }
                      }
                      else
                      {
                        _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 66;
                      }
                    }
                    else
                    {
                      _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 59;
                    }
                  }
                  else
                  {
                    _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 58;
                  }
                }
                else
                {
                  _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 57;
                }
              }
              else
              {
                if ( v9 == 1 )
                {
                  _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 54;
                }
                else
                {
                  if ( building_64_house_clinic[128 * buildingId] )
                    _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 55;
                  else
                    _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 56;
                }
              }
            }
            else
            {
              _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 53;
            }
          }
          else
          {
            _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 52;
          }
        }
        else
        {
          if ( building_6e_house_entertainment[128 * buildingId] )
          {
            if ( v15 >= 10 )
            {
              if ( v15 >= 25 )
              {
                if ( v15 >= 50 )
                {
                  if ( v15 >= 80 )
                    _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 38;
                  else
                    _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 37;
                }
                else
                {
                  _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 36;
                }
              }
              else
              {
                _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 35;
              }
            }
            else
            {
              _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 34;
            }
          }
          else
          {
            _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 33;
          }
        }
      }
      else
      {
        if ( dword_64E378 )
          _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 62;
        else
          _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 30;
      }
    }
    else
    {
      if ( reqHealth == 1 )
      {
        _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 24;
      }
      else
      {
        if ( building_64_house_clinic[128 * buildingId] )
          _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 25;
        else
          _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 26;
      }
    }
  }
  else
  {
    if ( building_6e_house_entertainment[128 * buildingId] )
    {
      if ( reqEntertainment >= 10 )
      {
        if ( reqEntertainment >= 25 )
        {
          if ( reqEntertainment >= 50 )
          {
            if ( reqEntertainment >= 80 )
              _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 8;
            else
              _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 7;
          }
          else
          {
            _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 6;
          }
        }
        else
        {
          _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 5;
        }
      }
      else
      {
        _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 4;
      }
    }
    else
    {
      _HIBYTE(buildings[buildingId].wharf_hasBoat_house_evolveStatusDesir) = 3;
    }
  }
}
