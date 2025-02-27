$NetBSD: patch-src_3rdparty_chromium_weblayer_common_weblayer__paths.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/weblayer/common/weblayer_paths.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ src/3rdparty/chromium/weblayer/common/weblayer_paths.cc
@@ -17,7 +17,7 @@
 
 #if defined(OS_WIN)
 #include "base/base_paths_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "base/nix/xdg_util.h"
 #endif
 
@@ -35,7 +35,7 @@ bool GetDefaultUserDataDirectory(base::F
     return false;
   *result = result->AppendASCII("weblayer");
   return true;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   base::FilePath config_dir(base::nix::GetXDGDirectory(
       env.get(), base::nix::kXdgConfigHomeEnvVar, base::nix::kDotConfigDir));
