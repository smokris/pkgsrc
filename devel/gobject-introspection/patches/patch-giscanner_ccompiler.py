$NetBSD$

Do not add every -L argument to LD_LIBRARY_PATH on SunOS.

--- giscanner/ccompiler.py.orig	2020-10-03 10:23:41.000000000 +0000
+++ giscanner/ccompiler.py
@@ -215,7 +215,8 @@ class CCompiler(object):
                     else:
                         args.append('-Wl,-rpath,' + library_path)
 
-            runtime_paths.append(library_path)
+            if not sys.platform.startswith('sunos'):
+                runtime_paths.append(library_path)
 
         for library in libraries + extra_libraries:
             if self.check_is_msvc():
