# $NetBSD: Makefile,v 1.1 2021/09/20 02:48:37 mef Exp $

R_PKGNAME=	insight
R_PKGVER=	0.14.4

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Easy Access to Model Information for Various Model Objects
LICENSE=	gnu-gpl-v3

# Packages suggested but not available:
#   'AER', 'afex', 'aod', 'BayesFactor', 'bayestestR', 'bdsmatrix',
#   'betareg', 'biglm', 'blavaan', 'blme', 'brms', 'censReg', 'cgam',
#   'clubSandwich', 'coxme', 'cplm', 'crch', 'effectsize', 'emmeans',
#   'epiR', 'estimatr', 'feisr', 'fixest', 'fungible', 'gam', 'gamlss',
#   'gamm4', 'gbm', 'gee', 'geepack', 'GLMMadaptive', 'glmmTMB', 'gmnl',
#   'gt', 'ivreg', 'JM', 'lavaan', 'lfe', 'logistf', 'mclust',
#   'MCMCglmm', 'merTools', 'metaBMA', 'mice', 'mlogit', 'multgee',
#   'nonnest2', 'ordinal', 'panelr', 'parameters', 'parsnip',
#   'performance', 'plm', 'pscl', 'rms', 'robustlmm', 'rstanarm',
#   'rstantools', 'speedglm', 'tripack', 'truncreg'


TEST_DEPENDS+=	R-VGAM-[0-9]*:../../math/R-VGAM
TEST_DEPENDS+=	R-bbmle-[0-9]*:../../math/R-bbmle
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-httr-[0-9]*:../../www/R-httr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-lme4-[0-9]*:../../math/R-lme4
TEST_DEPENDS+=	R-lmtest-[0-9]*:../../math/R-lmtest
TEST_DEPENDS+=	R-psych-[0-9]*:../../math/R-psych
TEST_DEPENDS+=	R-quantreg-[0-9]*:../../math/R-quantreg
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-robustbase-[0-9]*:../../math/R-robustbase
TEST_DEPENDS+=	R-rstudioapi-[0-9]*:../../math/R-rstudioapi
TEST_DEPENDS+=	R-sandwich-[0-9]*:../../math/R-sandwich
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-statmod-[0-9]*:../../math/R-statmod
TEST_DEPENDS+=	R-survey-[0-9]*:../../math/R-survey
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
