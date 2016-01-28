# Copyright (C) 2014 4DIAC
#
# See CREDITS for details about who has contributed to this project.
#
# For further information about the PTXdist project and license conditions
# see the README file.
#

#
# We provide this package
#
PACKAGES-$(PTXCONF_FORTE_WAGO) += forte_wago

#
# Paths and names
#
ifdef PTXCONF_FORTE_WAGO_TRUNK
FORTE_WAGO_VERSION	:= trunk
else
FORTE_WAGO_VERSION	:= 1.6.2
endif
FORTE_WAGO			:= forte_wago-$(FORTE_WAGO_VERSION)
FORTE_WAGO_URL		:= file:///<Path to your forte main directory>
FORTE_WAGO_DIR		:= $(BUILDDIR)/$(FORTE_WAGO)
FORTE_WAGO_LICENSE	:= Eclipse Public License

# ----------------------------------------------------------------------------
# Get
# ----------------------------------------------------------------------------

$(FORTE_WAGO_SOURCE):
	@$(call targetinfo)
	@$(call get, FORTE_WAGO)

# ----------------------------------------------------------------------------
# Prepare
# ----------------------------------------------------------------------------

#FORTE_WAGO_CONF_ENV	:= $(CROSS_ENV)

#
# cmake
#
FORTE_WAGO_CONF_TOOL	:= cmake
FORTE_WAGO_CONF_OPT	:= $(CROSS_CMAKE_USR) -DFORTE_COM_ETH:BOOL=ON -DFORTE_COM_FBDK:BOOL=ON -DFORTE_COM_LOCAL:BOOL=ON  -DFORTE_ARCHITECTURE:STRING=Posix -DFORTE_MODULE_CONVERT:BOOL=ON -DFORTE_TRACE_EVENTS:BOOL=OFF -DFORTE_MODULE_WagoKbus=ON
#
# ----------------------------------------------------------------------------
# Target-Install
# ----------------------------------------------------------------------------

$(STATEDIR)/forte_wago.targetinstall:
	@$(call targetinfo)

	@$(call install_init, forte_wago)
	@$(call install_fixup, forte_wago, PRIORITY, optional)
	@$(call install_fixup, forte_wago, SECTION, base)
	@$(call install_fixup, forte_wago, AUTHOR, "4DIAC Consortium")
	@$(call install_fixup, forte_wago, DESCRIPTION, missing)

#	#
#	# example code:; copy all binaries
#	#

	@for i in $(shell cd $(FORTE_WAGO_PKGDIR) && find bin sbin usr/bin usr/sbin -type f); do \
		$(call install_copy, forte_wago, 0, 0, 0755, -, /$$i); \
	done

#	#
#	# FIXME: add all necessary things here
#	#

	@$(call install_finish, forte_wago)

	@$(call touch)

# ----------------------------------------------------------------------------
# Clean
# ----------------------------------------------------------------------------
forte_wago_clean:
	rm -rf $(STATEDIR)/forte_wago.*
#$(STATEDIR)/forte_wago.clean:
#	@$(call targetinfo)
#	@$(call clean_pkg, FORTE_WAGO)

# vim: syntax=make
