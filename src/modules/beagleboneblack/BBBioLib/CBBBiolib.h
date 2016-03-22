/*************************************************************************
 *** BBBiolib base class to handle initialization and common parameters
 ***
 *** Name: CBBBiolib
 *** Version:
 ***     0.0: 2015-09-09/EQUEROL - UJI -
 *************************************************************************/

#ifndef _CBBBIOLIB_H_
#define _CBBBIOLIB_H_
#include "BBBiolib.h"
class CBBBiolib {
public:
	CBBBiolib();
	virtual ~CBBBiolib();
protected:
    /*! \brief Initialize BBBiolib library
     *
     *  This functions initializes BBBiolib and tracks the number of users currently using the library
     *  \return 0 on init success; -1 on fail
     */
	static int initBBBioLib();
    /*! \brief Desinitialize BBBiolib library
     *
     *  When this function is called library user number is reduced by 1. If there is 0 users
     *  this functions desintializes BBBiolib
     *  \return 0 on success; -1 on fail
     */
	static int freeBBBioLib();
    /*! \brief Adds a user to the library user count
     *
     *  This functions checks if the calling class has already joined the library. If it has not it
     *  tries to initialize it and adds a new user .
     */
	int joinBBBioLib();
    /*! \brief Removes a user from the library user count
     *
     *  This functions checks if the calling class has already joined the library. If it has joined it,
     *  an user is removed.
     */
	int leaveBBBioLib();
private:
	static unsigned int sm_nLibUsers;
	bool m_bHasJoined = false;
};

#endif /*_CBBBIOLIB_H_ */
