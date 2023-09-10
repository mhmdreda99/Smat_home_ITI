/**
 * @file GPI_Interface.h
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GPI_INTERFACE_H_
#define GPI_INTERFACE_H_


/*********************************************************************************/
/* Function: GPI_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize General Interrupt Enable			       	    **/
/*********************************************************************************/
void GPI_voidInit   (void);

/*********************************************************************************/
/* Function: GPI_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function enables General Interrupt Enable (GIE)		       	    **/
/*********************************************************************************/
void GPI_voidEnable (void);

/*********************************************************************************/
/* Function: GPI_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function disables General Interrupt Enable (GIE)		       	    **/
/*********************************************************************************/
void GPI_voidDisable(void);




#endif /* GPI_INTERFACE_H_ */
