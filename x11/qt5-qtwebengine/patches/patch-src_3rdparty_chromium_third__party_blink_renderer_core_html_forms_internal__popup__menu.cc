$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_core_html_forms_internal__popup__menu.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/third_party/blink/renderer/core/html/forms/internal_popup_menu.cc.orig	2020-07-15 18:56:02.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/html/forms/internal_popup_menu.cc
@@ -113,7 +113,7 @@ class InternalPopupMenu::ItemIterationCo
         is_in_group_(false),
         buffer_(buffer) {
     DCHECK(buffer_);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // On other platforms, the <option> background color is the same as the
     // <select> background color. On Linux, that makes the <option>
     // background color very dark, so by default, try to use a lighter
