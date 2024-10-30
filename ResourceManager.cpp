#include "ResourceManager.h"
#include <iostream>
#include <algorithm>

ResourceManager* ResourceManager::Singleton = nullptr;

/**
 * @brief Constructor for the ResourceManager class.
 * 
 * Initializes resource levels and budget to zero.
 */
ResourceManager::ResourceManager()
{ 
	this->waterLevel = 0;
	this->energyLevel = 0;
	this->budget = 0.0;
	this->wood = 0;
	this->steel = 0;
	this->generalMaterials = 0;
}

/**
 * @brief Gets the singleton instance of ResourceManager.
 * 
 * If the instance does not exist, it creates one. 
 * @return Pointer to the instance of ResourceManager.
 */
ResourceManager* ResourceManager::instance() 
{
    if (Singleton == nullptr) 
	{
        Singleton = new ResourceManager();
    }

    return Singleton;
}

/**
 * @brief Decreases resource levels based on the provided amounts.
 * 
 * Checks if there are enough resources before decreasing. 
 * @param water Amount of water to decrease.
 * @param energy Amount of energy to decrease.
 * @param wood Amount of wood to decrease.
 * @param steel Amount of steel to decrease.
 * @param materials Amount of general materials to decrease.
 * @return True if resources were successfully decreased, false otherwise.
 */
bool ResourceManager::decreaseResourceLevels(int water, int energy, int wood, int steel, int materials) 
{
    if ((this->waterLevel - water < 0) || (this->energyLevel - energy < 0) || (this->wood - wood < 0) || (this->steel - steel < 0) || (this->generalMaterials - materials < 0)) //check enough resources
    {
        std::cout << "Not enough resources";
        return false;
    }

    this->waterLevel -= water;
    this->energyLevel -= energy;
    this->wood -= wood;
    this->steel -= steel;
    this->generalMaterials -= materials;

    std::cout << "Updated City resource levels - Water: " << this->waterLevel
              << ", Energy: " << this->energyLevel
              << ", Wood: " << this->wood
              << ", Steel: " << this->steel
              << ", General Materials: " << this->generalMaterials << std::endl;

    return true;
}

/**
 * @brief Decreases the budget by the specified amount.
 * 
 * Checks if there is enough budget before decreasing. 
 * @param money Amount of money to decrease.
 * @return True if the budget was successfully decreased, false otherwise.
 */
bool ResourceManager::decreaseBudget(int money)
{
    if (this->budget - money < 0)
    {
        std::cout << "Not enough budget" << std::endl;
        return false;
    }

	this->budget -= money;

	std::cout << "Updated City Budget: " << this->budget << std::endl;

    return true;
}

/**
 * @brief Increases resource levels based on the provided amounts.
 * 
 * @param water Amount of water to increase.
 * @param energy Amount of energy to increase.
 * @param wood Amount of wood to increase.
 * @param steel Amount of steel to increase.
 * @param materials Amount of general materials to increase.
 */
void ResourceManager::increaseResourceLevels(int water, int energy, int wood, int steel, int materials)
{
    this->waterLevel += water;
    this->energyLevel += energy;
    this->wood += wood;
    this->steel += steel;
    this->generalMaterials += materials;

    std::cout << "Updated City resource levels - Water: " << this->waterLevel
              << ", Energy: " << this->energyLevel
              << ", Wood: " << this->wood
              << ", Steel: " << this->steel
              << ", General Materials: " << this->generalMaterials << std::endl;
}

/**
 * @brief Increases the budget by the specified amount.
 * 
 * @param money Amount of money to increase.
 */
void ResourceManager::increaseBudget(int money)
{
    this->budget += money;

    std::cout << "Updated City Budget: " << this->budget << std::endl;
}

/**
 * @brief Destructor for the ResourceManager class.
 * 
 * Cleans up resources and nullifies the Singleton pointer if this
 * instance is being destroyed.
 */
ResourceManager::~ResourceManager() 
{
    // Delete all Building pointers in buildingList
    // for (Building* building : buildingList) 
    // {
    //     delete building;
    // }

    // buildingList.clear();

    // Delete all Department pointers in departmentList
    // for (Department* department : departmentList) 
    // {
    //     delete department;
    // }

    // departmentList.clear();

    // Nullify the Singleton pointer if this is the instance being destroyed
    if (Singleton == this) 
    {
        Singleton = nullptr;
    }
}

//BELOW ARE FUNCTIONS THAT WERE IMPLEMENTED IN THE OBSERVER PATTERN FOR RESOURCE MANAGER WHICH I DON'T THINK IS NECESSARY

// bool ResourceManager::attachBuilding(Building* building) 
// {
// 	if (building != nullptr) 
// 	{
//         buildingList.push_back(building);

//         return true;
//     }

//     return false;
// }

// bool ResourceManager::detachBuilding(Building* building) 
// {
// 	auto it = std::find(buildingList.begin(), buildingList.end(), building);

//     if (it != buildingList.end()) 
// 	{
//         buildingList.erase(it);
//         return true;
//     }
	
//     return false;
// }

// void ResourceManager::notify() 
// {
// 	for (Building* building : buildingList) 
// 	{
//         if (building) 
// 		{
//             building->update();
//         }
//     }

//     for (Department* department : departmentList) 
// 	{
//         if (department) 
// 		{
//             department->update(); 
//         }
//     }
// }

// bool ResourceManager::attachDepartment(Department* department) 
// {
// 	if (department != nullptr) 
// 	{
//         departmentList.push_back(department);

//         return true;
//     }

//     return false;
// }

// bool ResourceManager::detachDepartment(Department* department) 
// {
// 	auto it = std::find(departmentList.begin(), departmentList.end(), department);

//     if (it != departmentList.end()) 
// 	{
//         departmentList.erase(it);
//         return true;
//     }
//     return false;
// }
