/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _IF2INDCO_H_
#define _IF2INDCO_H_

#include "./datatypes/forte_any.h"
#include "dataconn.h"
#include "funcbloc.h"
#include "fortelist.h"

/*! \ingroup CORE\brief class for handling a interface to internal data connection.
 *  @author GG
 *  @version 20081121/mmm - changed due to elimination of ANY_FACADE
 *  @version 20071029/az - changed constructor of interface data connections
 *  @version 20060718/gugr - Initial version to handle data connections from CFB interface to internal FBs
 */

class CInterface2InternalDataConnection : public CDataConnection{
  public:
    CInterface2InternalDataConnection();
    virtual ~CInterface2InternalDataConnection();

    /*! \brief Clones interface data value (CFB data input) to internal FB data input.
     */
    void cloneInputInterfaceValue(void);

    void setSource(CFunctionBlock *paSrcFB, TPortId paSrcPortId);

  protected:

  private:

};

typedef CInterface2InternalDataConnection *TCInterface2InternalDataConnectionPtr;

#endif /*IF2INDCO_H_*/
