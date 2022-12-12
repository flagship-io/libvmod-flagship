#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <libflagship_linux_amd64.h>

#include "cache/cache.h"

#include "vtim.h"
#include "vcc_flagship_if.h"

VCL_VOID
vmod_init(VRT_CTX, VCL_STRING envId, VCL_STRING apiKey, VCL_INT pollingInterval, VCL_STRING logLevel, VCL_INT trackingEnabled)
{
	initFlagship(strdup(envId), strdup(apiKey), pollingInterval, strdup(logLevel), trackingEnabled);
}

VCL_INT
vmod_get_flag_bool(VRT_CTX, VCL_STRING visitorId, VCL_STRING context, VCL_STRING key, VCL_INT defaultValue, VCL_INT activate)
{	
	return getFlagBool(strdup(visitorId), strdup(context), strdup(key), defaultValue, activate);
}

VCL_STRING
vmod_get_flag_string(VRT_CTX, VCL_STRING visitorId, VCL_STRING context, VCL_STRING key, VCL_STRING defaultValue, VCL_INT activate)
{	
	char *buf = getFlagString(strdup(visitorId), strdup(context), strdup(key), strdup(defaultValue), activate);
	return buf;
}

VCL_REAL
vmod_get_flag_number(VRT_CTX, VCL_STRING visitorId, VCL_STRING context, VCL_STRING key, VCL_REAL defaultValue, VCL_INT activate)
{	
	return getFlagNumber(strdup(visitorId), strdup(context), strdup(key), defaultValue, activate);
}

VCL_STRING
vmod_compute_flags(VRT_CTX, VCL_STRING visitorId, VCL_STRING context)
{	
	char *buf = getAllFlags(strdup(visitorId), strdup(context));
	return buf;
}
