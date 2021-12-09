$NetBSD: patch-ext_intl_breakiterator_codepointiterator__internal.cpp,v 1.2 2021/12/08 23:55:19 tnn Exp $

Use stdbool true/false macros.
php73-intl: fix icu>=70 fallout. Backport from php74-intl.

--- ext/intl/breakiterator/codepointiterator_internal.cpp.orig	2021-11-16 11:18:31.000000000 +0000
+++ ext/intl/breakiterator/codepointiterator_internal.cpp
@@ -58,7 +58,7 @@ CodePointBreakIterator& CodePointBreakIt
 		return *this;
 	}
 
-	this->fText = utext_clone(this->fText, that.fText, FALSE, TRUE, &uec);
+	this->fText = utext_clone(this->fText, that.fText, false, true, &uec);
 
 	//don't bother copying the character iterator, getText() is deprecated
 	clearCurrentCharIter();
@@ -75,20 +75,24 @@ CodePointBreakIterator::~CodePointBreakI
 	clearCurrentCharIter();
 }
 
+#if U_ICU_VERSION_MAJOR_NUM >= 70
+bool CodePointBreakIterator::operator==(const BreakIterator& that) const
+#else
 UBool CodePointBreakIterator::operator==(const BreakIterator& that) const
+#endif
 {
 	if (typeid(*this) != typeid(that)) {
-		return FALSE;
+		return false;
 	}
 
 	const CodePointBreakIterator& that2 =
 		static_cast<const CodePointBreakIterator&>(that);
 
 	if (!utext_equals(this->fText, that2.fText)) {
-		return FALSE;
+		return false;
 	}
 
-	return TRUE;
+	return true;
 }
 
 CodePointBreakIterator* CodePointBreakIterator::clone(void) const
@@ -109,7 +113,7 @@ CharacterIterator& CodePointBreakIterato
 
 UText *CodePointBreakIterator::getUText(UText *fillIn, UErrorCode &status) const
 {
-	return utext_clone(fillIn, this->fText, FALSE, TRUE, &status);
+	return utext_clone(fillIn, this->fText, false, true, &status);
 }
 
 void CodePointBreakIterator::setText(const UnicodeString &text)
@@ -128,7 +132,7 @@ void CodePointBreakIterator::setText(UTe
 		return;
 	}
 
-	this->fText = utext_clone(this->fText, text, FALSE, TRUE, &status);
+	this->fText = utext_clone(this->fText, text, false, true, &status);
 
 	clearCurrentCharIter();
 }
@@ -280,7 +284,7 @@ CodePointBreakIterator &CodePointBreakIt
 	}
 
 	int64_t pos = utext_getNativeIndex(this->fText);
-	this->fText = utext_clone(this->fText, input, FALSE, TRUE, &status);
+	this->fText = utext_clone(this->fText, input, false, true, &status);
 	if (U_FAILURE(status)) {
 		return *this;
 	}
