$NetBSD: patch-src_3rdparty_chromium_ui_views_controls_textfield_textfield.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/views/controls/textfield/textfield.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/ui/views/controls/textfield/textfield.cc
@@ -62,7 +62,7 @@
 #include "base/win/win_util.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/linux/text_edit_key_bindings_delegate_auralinux.h"
 #endif
@@ -183,14 +183,14 @@ ui::TextEditCommand GetCommandForKeyEven
 #endif
         return ui::TextEditCommand::DELETE_BACKWARD;
       }
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift)
         return ui::TextEditCommand::DELETE_TO_BEGINNING_OF_LINE;
 #endif
       return ui::TextEditCommand::DELETE_WORD_BACKWARD;
     case ui::VKEY_DELETE:
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift && control)
         return ui::TextEditCommand::DELETE_TO_END_OF_LINE;
@@ -258,7 +258,7 @@ bool IsControlKeyModifier(int flags) {
 // Control-modified key combination, but we cannot extend it to other platforms
 // as Control has different meanings and behaviors.
 // https://crrev.com/2580483002/#msg46
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return flags & ui::EF_CONTROL_DOWN;
 #else
   return false;
@@ -691,7 +691,7 @@ bool Textfield::OnMousePressed(const ui:
 #endif
   }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (!handled && !had_focus && event.IsOnlyMiddleMouseButton())
     RequestFocusWithPointer(ui::EventPointerType::POINTER_TYPE_MOUSE);
 #endif
@@ -737,7 +737,7 @@ bool Textfield::OnKeyPressed(const ui::K
   if (!textfield)
     return handled;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
   std::vector<ui::TextEditCommandAuraLinux> commands;
@@ -886,7 +886,7 @@ void Textfield::AboutToRequestFocusFromT
 }
 
 bool Textfield::SkipDefaultKeyEventProcessing(const ui::KeyEvent& event) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Skip any accelerator handling that conflicts with custom keybindings.
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
@@ -2146,7 +2146,7 @@ bool Textfield::PasteSelectionClipboard(
 }
 
 void Textfield::UpdateSelectionClipboard() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (text_input_type_ != ui::TEXT_INPUT_TYPE_PASSWORD) {
     ui::ScopedClipboardWriter(ui::ClipboardBuffer::kSelection)
         .WriteText(GetSelectedText());
