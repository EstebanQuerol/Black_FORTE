/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#include "ecet.h"
#include "funcbloc.h"
#include "fbcontainer.h"

#ifdef FORTE_SUPPORT_MONITORING
#include <monitoring.h>
#endif

class CDevice;

/*! \ingroup CORE\brief Base class for all resources handling the reconfiguration management within this
 * resource and the background execution of event chains.
 *
 * CResource is inherited from CFBContainer in order to make the implementation of getResource easier. Furthermore
 * also the forwarding of management commands is less effort.
 * TODO think if CFBContainer inheritance should be public or private
 */
class CResource : public CFunctionBlock, public forte::core::CFBContainer{

  public:
    CSyncObject m_oResDataConSync;
    /*! \brief The main constructor for a resource.
     *
     * The resource can only be generated with a given device the resource is contained. A resource can not exist outside of an device.
     *  \param pa_poDevice           the device the resource is contained in
     *  \param pa_pstInterfaceSpec   interface-specification of resource
     *  \param pa_nInstanceNameId    StringId of instance-name
     *  \param pa_roObjectHandler    reference to object handler
     *  \param pa_acFBData           Byte-array for resource-specific data
     */
    CResource(CResource* pa_poDevice, const SFBInterfaceSpec *pa_pstInterfaceSpec,
        const CStringDictionary::TStringId pa_nInstanceNameId,
        TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData);

    virtual ~CResource();

    /*!\brief Execute the given management command
     *
     * Evaluates the m_sDestination parameter of the command if empty the resource tries
     * to execute the management command if not it tries to apply the mgm command to a
     * contained FB if possible.
     * \param paCommand internal representation of the management command
     * \return response of the MGMCommand execution as defined in IEC 61499
     */
    virtual EMGMResponse executeMGMCommand(forte::core::SManagementCMD &paCommand);

    /*! \brief Get the device the resource is contained in
     */
    CDevice &getDevice(void){
      return (CDevice &) getResource();
    }
    ;

    CEventChainExecutionThread *getResourceEventExecution(void){
      return m_poResourceEventExecution;
    }
    ;

    virtual EMGMResponse changeFBExecutionState(EMGMCommandType pa_unCommand);

#ifdef FORTE_SUPPORT_MONITORING
    forte::core::CMonitoringHandler &getMonitoringHandler(){
      return mMonitoringHandler;
    }
#endif

  protected:
    CResource(const SFBInterfaceSpec *pa_pstInterfaceSpec,
        const CStringDictionary::TStringId pa_nInstanceNameId,
        TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData);

    virtual void executeEvent(int){
    }

    /*!Wrapper for simplifying connection creation in resources
     *
     */
    EMGMResponse createConnection(forte::core::SManagementCMD &paCommand);
  private:
    /*!\brief Create a new connection between source and destination
     *
     * This function is protected so that devices and resource can utilize to setup their connections.
     * @param  paSrcNameList identifier name list for the source of the connection
     * @param  padstNameList identifier name list for the destination of the connection
     * @return response of the command execution as defined in IEC 61499
     */
    EMGMResponse createConnection(forte::core::TNameIdentifier &paSrcNameList,
        forte::core::TNameIdentifier &paDstNameList);

    /*! Handle and perform the actions required for an execution state change
     * command (i.e., START, STOP, KILL, RESET)
     *
     * @param paCMD    the ecuctoin state change command to be performed
     * @param paTarget identifier which is the target for this request if empty the target is the resource
     * @return response of the command execution as defined in IEC 61499
     */
    EMGMResponse handleExecutionStateCmd(EMGMCommandType paCMD,
        forte::core::TNameIdentifier &paTarget);

    /*!\brief Create a new connection between source and destination
     *
     * @param  paSrcNameList identifier name list for the source of the connection
     * @param  padstNameList identifier name list for the destination of the connection
     * @return response of the command execution as defined in IEC 61499
     */
    EMGMResponse deleteConnection(forte::core::TNameIdentifier &paSrcNameList,
        forte::core::TNameIdentifier &paDstNameList);

    /*!\brief Write a parameter value to a given FB-input
     *
     * @param paNameList the identifier name list of the parameter to be written
     * @param paValue the value to be writen
     * @return response of the command execution as defined in IEC 61499
     */
    EMGMResponse writeValue(forte::core::TNameIdentifier &paNameList, const CIEC_STRING & paValue);

    /*!\brief Read a parameter value from a given FB
     *
     * @param paNameList the identifier name list of the parameter to be read
     * @param paValue the destination for the value to be read
     * @return response of the command execution as defined in IEC 61499
     */
    EMGMResponse readValue(forte::core::TNameIdentifier &paNameList, CIEC_STRING & paValue);

    /*!\brief get the variable with the given name identifier
     *
     * @param paNameList the identifier name list of the variable to be retrieved
     * @return the pointer to the variable or 0 if the variable with the given identifier name list does not exist
     */
    CIEC_ANY *getVariable(forte::core::TNameIdentifier &paNameList);

    /*!\brief get the connection object for the given source identifier
     *
     * @param paSrcNameList array of the name hierarchy the requested connection source
     * @return pointer to the requested connection, returns 0 if there is no such source
     */
    CConnection *getConnection(forte::core::TNameIdentifier &paSrcNameList);

    CConnection *getResIf2InConnection(CStringDictionary::TStringId paResInput) const;

    void initializeResIf2InConnections();

    /*!\brief The event chain execution of background (low priority) event chains started within this resource
     */
    CEventChainExecutionThread *m_poResourceEventExecution;

    CInterface2InternalDataConnection *mResIf2InConnections; //!< List of all connections from the res interface to internal FBs

#ifdef FORTE_SUPPORT_MONITORING
    forte::core::CMonitoringHandler mMonitoringHandler;
#endif //#ifdef FORTE_SUPPORT_MONITORING

};

#endif /*RESOURCE_H_*/
