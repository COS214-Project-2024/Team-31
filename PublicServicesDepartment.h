#ifndef PUBLICSERVICESDEPARTMENT_H
#define PUBLICSERVICESDEPARTMENT_H

#include "Department.h"
#include "Building.h"
#include "TaxCommand.h"

/**
 * @class PublicServicesDepartment
 * @brief The PublicServicesDepartment class represents a department responsible for 
 * collecting various taxes and implementing the singleton design pattern.
 */
class PublicServicesDepartment : public Department
{
private:
	///< Pointer to the singleton instance of PublicServicesDepartment.
	static PublicServicesDepartment* Singleton;

	///< Array of pointers to TaxCommand objects for different tax types.
	TaxCommand* commands[3];

public:
	/**
     * @brief Constructs a PublicServicesDepartment and initializes the tax command objects.
     */
	PublicServicesDepartment();

	/**
     * @brief Collects the specified type of tax by executing the relevant tax command.
     * 
     * @param tax The type of tax to be collected (income, property, or sales).
     */
	void collectTax(std::string tax);

	/**
     * @brief Returns the singleton instance of the PublicServicesDepartment.
     * 
     * @return PublicServicesDepartment* Pointer to the singleton instance.
     */
	static PublicServicesDepartment* instance();

	/**
     * @brief Destructor for the PublicServicesDepartment, cleaning up dynamically allocated resources.
     */
	~PublicServicesDepartment();
};

#endif