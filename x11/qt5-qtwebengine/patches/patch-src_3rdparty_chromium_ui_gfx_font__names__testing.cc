$NetBSD: patch-src_3rdparty_chromium_ui_gfx_font__names__testing.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/gfx/font_names_testing.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/font_names_testing.cc
@@ -22,7 +22,7 @@ Note that we have to support the full ra
 dessert.
 */
 
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const char kTestFontName[] = "Arimo";
 #elif defined(OS_ANDROID)
 const char kTestFontName[] = "sans-serif";
@@ -30,7 +30,7 @@ const char kTestFontName[] = "sans-serif
 const char kTestFontName[] = "Arial";
 #endif
 
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const char kSymbolFontName[] = "DejaVu Sans";
 #elif defined(OS_ANDROID)
 const char kSymbolFontName[] = "monospace";
@@ -40,7 +40,7 @@ const char kSymbolFontName[] = "Segoe UI
 const char kSymbolFontName[] = "Symbol";
 #endif
 
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const char kCJKFontName[] = "Noto Sans CJK JP";
 #elif defined(OS_ANDROID)
 const char kCJKFontName[] = "serif";
