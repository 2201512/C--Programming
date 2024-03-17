/*!*************************************************************************
****
\file ocean.cpp
\author Yugendren S/O Sooriya Moorthi
\par DP email: 2201512@sit.singaporetech.edu.sg
\par Course: HLP2
\par Section: nil
\par Ass 02
\date 19-01-2023
\brief
This program header file for functions used in ocean-driver.cpp. The functions include:
- creat ocean, destroy ocean, placeboat, takeshot
    takes inputs from ocean-driver, malloc, and delete memory, while simulating
    placements of boats and shots onto the ocean.
****************************************************************************
***/
#include "ocean.h"
#include <iostream> // std::cout
#include <iomanip>  // std::setw

namespace HLP2 {
  namespace WarBoats {
    int const BOAT_LENGTH {4};   //!< Length of a boat
    int const HIT_OFFSET  {100}; //!< Add this to the boat ID
    
    /**************************************************************************/
    /*!
      \brief
        Memorary allocates the function
      
      \param int num_boats
        The num of boats to be used
      
      \param int x_size
        x size of ocean to malloc.
      
      \param int y_size
        y size of ocean to malloc
        
      \return showboats
        a pointer to the allocated ocean
    */
    /**************************************************************************/
    Ocean* CreateOcean(int num_boats, int x_size, int y_size)//new and set values to 0
    {
      auto rocean = new Ocean; //dynamically allocate a ocean object
      rocean->stats.hits = 0;//initialize all to 0
      rocean->stats.misses = 0;
      rocean->stats.duplicates = 0;
      rocean->stats.sunk = 0;
      rocean->num_boats = num_boats;
      //rocean->boats = new boat[x_size*y_size/4];
      rocean->x_size = x_size;//initialize values
      rocean->y_size = y_size;//initalise values
      rocean->grid = new int [x_size*y_size]; //dynamically allocate 2D array x_size x y_size
      for(int x =0; x < x_size; x++) //each position to constant dtOK
      {
        for(int y =0; y < x_size*y_size; y++)
        {
          rocean->grid[y] = DamageType::dtOK;//inialise all grid to 0
        }
      }
      rocean->boats = new Boat [num_boats];//dynamically allocate no of boats of Boats
      rocean->boats->hits = 0;
      rocean->boats->ID = 0;
      return rocean;
    }
    
    /**************************************************************************/
    /*!
      \brief
        Memorary deallocates the function
      
      \param Ocean *theOcean
        The pointer to the allocated ocean
    */
    /**************************************************************************/
    void DestroyOcean(Ocean *theOcean)//delete and put to nullptr
    {
      delete[] theOcean->boats;//delete boats5
      theOcean->boats = nullptr;
      delete[] theOcean->grid;//delete grid
      theOcean->grid = nullptr;
      delete[] theOcean;//delete whole object
      theOcean = nullptr;
    }
    
    /**************************************************************************/
    /*!
      \brief
        places boats on the map, if it is legall
      
      \param Ocean& ocean
        reference to the ocean read and write
      
      \param Boat const& boat
        a constant reference to the ocean to read.
        
      \return BoatPlacement
        a value indicating if placement is valid
    */
    /**************************************************************************/
    BoatPlacement PlaceBoat(Ocean& ocean, Boat const& boat)
    {
      //if ID beyond num_boat, reject
      if (ocean.boats->ID >= ocean.num_boats) 
      {
        return bpREJECTED;
      }
      //if horizontal
      if(boat.orientation == oHORIZONTAL)
      {
        if((boat.position.x <= ocean.x_size - BOAT_LENGTH || boat.position.x >= 0) && (boat.position.y <= ocean.y_size || boat.position.y >= 0))
        {
          for(int z =0; z<BOAT_LENGTH; z++)
          {
            if(ocean.grid[ocean.x_size*boat.position.y+(boat.position.x+z)]!=dtOK)
            {
              return bpREJECTED;
            }
          }
            ocean.boats->ID++;
          
          for (int i = 0; i < BOAT_LENGTH; i++)
          { 
            ocean.grid[boat.position.y * ocean.x_size + boat.position.x + i] = ocean.boats->ID;
          }
        }
      }
      else if(boat.orientation == oVERTICAL)//if vertical
      {
        if ((boat.position.y <= ocean.y_size - BOAT_LENGTH || boat.position.y >= 0) && (boat.position.x <= ocean.x_size || boat.position.x >= 0)) 
        {

          for(int z =0; z<BOAT_LENGTH; z++)//if fail, cus shot alr or taken
          {
            if (ocean.grid[(boat.position.y + z) * ocean.x_size + boat.position.x] != dtOK) 
            {
             return bpREJECTED;
            }
          }
            ocean.boats->ID++;
          
            for(int z =0; z<BOAT_LENGTH; z++)// replace spaces with boat
            {
              ocean.grid[(boat.position.y + z) * ocean.x_size + boat.position.x] = ocean.boats->ID;
            }  
        }
      }
      return bpACCEPTED;//if pass thru checks and replacement.
    }
    
    /**************************************************************************/
    /*!
      \brief
        simulates a shot and adjusts the map while returning result
      
      \param Ocean& ocean
        reference to the ocean to manupiulate.
      
      \param Point const& coordinate
        information of coordinate of shot to read
     
      \return ShotResult
        a value to represent result of shot taken
    */
    /**************************************************************************/
    ShotResult TakeShot(Ocean& ocean, Point const& coordinate)
    {
      int P = coordinate.y * ocean.x_size + coordinate.x;
      //int V = ocean.grid[coordinate.y * ocean.x_size + coordinate.x];

      if(!((coordinate.x <= ocean.x_size && coordinate.x >= 0) && (coordinate.y <= ocean.y_size && coordinate.y >= 0))) //if fail, not inside
      {
        return ShotResult:: srILLEGAL;
      }
      
      if(ocean.grid[P] == dtOK)
      {
        ocean.stats.misses++;
        ocean.grid[P] = dtBLOWNUP;
        return ShotResult:: srMISS;
      }
      else if(ocean.grid[P] == dtBLOWNUP || (ocean.grid[P]>= (1+HIT_OFFSET) && ocean.grid[P]<=(99+HIT_OFFSET)) )
      {
        ocean.stats.duplicates++;
        return ShotResult:: srDUPLICATE;
      }
      else if(ocean.grid[P]>=1 || ocean.grid[P]<=99)
      {
        ocean.stats.hits++;
        ocean.boats[ocean.grid[P]-1].hits++;
        ocean.grid[P]+=HIT_OFFSET;
        if(ocean.boats[ocean.grid[P]-101].hits==BOAT_LENGTH)
        {
          ocean.stats.sunk++;
          return ShotResult:: srSUNK;
        }
      }
      return ShotResult:: srHIT;
    } 
    /**************************************************************************/
    /*!
      \brief
        get statics of the ocean
      
      \param Ocean const& ocean
        reference to the ocean to read.
     
      \return ShotStats
        to return stats back to driver.
    */
    /**************************************************************************/
     ShotStats GetShotStats(Ocean const& ocean)
     {
        /*ShotStats v;
        v.hits = ocean.stats.hits;//initialize all to 0
        v.misses = ocean.stats.misses;
        v.duplicates = ocean.stats.duplicates;
        v.sunk = ocean.stats.sunk;
        return v;
        */
        return ocean.stats;
     }
    /**************************************************************************/
    /*!
      \brief
        Prints the grid (ocean) to the screen.
      
      \param ocean
        The Ocean to print
      
      \param field_width
        How much space each position takes when printed.
      
      \param extraline
        If true, an extra line is printed after each row. If false, no extra
        line is printed.
        
      \param showboats
        If true, the boats are shown in the output. (Debugging feature)
    */
    /**************************************************************************/
    void DumpOcean(const HLP2::WarBoats::Ocean &ocean,
                                    int field_width, 
                                    bool extraline, 
                                    bool showboats) {
      for (int y = 0; y < ocean.y_size; y++) { // For each row
        for (int x = 0; x < ocean.x_size; x++) { // For each column
            // Get value at x/y position
          int value = ocean.grid[y * ocean.x_size + x];
            // Is it a boat that we need to keep hidden?
          value = ( (value > 0) && (value < HIT_OFFSET) && (showboats == false) ) ? 0 : value;
          std::cout << std::setw(field_width) << value;
        }
        std::cout << "\n";
        if (extraline) { std::cout << "\n"; }
      }
    }
  } // namespace WarBoats
} // namespace HLP2
