$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_platform_fonts_font__metrics.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/font_metrics.cc.orig	2020-07-15 18:56:03.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/font_metrics.cc
@@ -38,7 +38,7 @@
 
 namespace blink {
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
 // This is the largest VDMX table which we'll try to load and parse.
 static const size_t kMaxVDMXTableSize = 1024 * 1024;  // 1 MB
 #endif
@@ -60,7 +60,7 @@ void FontMetrics::AscentDescentWithHacks
   int vdmx_ascent = 0, vdmx_descent = 0;
   bool is_vdmx_valid = false;
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
   // Manually digging up VDMX metrics is only applicable when bytecode hinting
   // using FreeType.  With DirectWrite or CoreText, no bytecode hinting is ever
   // done.  This code should be pushed into FreeType (hinted font metrics).
@@ -106,7 +106,7 @@ void FontMetrics::AscentDescentWithHacks
       visual_overflow_inflation_for_ascent = 1;
     if (descent < metrics.fDescent) {
       visual_overflow_inflation_for_descent = 1;
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
       // When subpixel positioning is enabled, if the descent is rounded down,
       // the descent part of the glyph may be truncated when displayed in a
       // 'overflow: hidden' container.  To avoid that, borrow 1 unit from the
