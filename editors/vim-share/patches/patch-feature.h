$NetBSD: patch-feature.h,v 1.5 2021/12/01 21:36:59 wiz Exp $

--- src/feature.h.orig	2019-12-03 21:59:23.000000000 +0000
+++ src/feature.h
@@ -814,7 +814,7 @@
 /*
  * SYS_VIMRC_FILE	Name of the system-wide .vimrc file.
  */
-// #define SYS_VIMRC_FILE	"/etc/vimrc"
+#define SYS_VIMRC_FILE "@PKG_SYSCONFDIR@/vimrc"
 
 /*
  * SYS_GVIMRC_FILE	Name of the system-wide .gvimrc file.
