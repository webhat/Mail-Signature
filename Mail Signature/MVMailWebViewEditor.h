@interface MailWebViewEditor : WebViewEditor <DOMEventListener>
{
    BOOL _needToFinishMakingPlainAfterRemovingStationery;
    NSMutableArray *_uneditedEditableElements;
    NSMutableArray *_editedEditableElements;
    DOMNode *_editableElementWithMouseDown;
    BOOL _shouldAttachFilesAtEnd;
    BOOL _isDeletingAllEncompassingSelection;
    NSArray *_backgroundTilingElements;
    NSArray *_backgroundTilingDivs;
    NSArray *_backgroundTilingFixedSizes;
}

@property(retain) NSArray *backgroundTilingFixedSizes; // @synthesize backgroundTilingFixedSizes=_backgroundTilingFixedSizes;
@property(retain) NSArray *backgroundTilingDivs; // @synthesize backgroundTilingDivs=_backgroundTilingDivs;
@property(retain) NSArray *backgroundTilingElements; // @synthesize backgroundTilingElements=_backgroundTilingElements;
- (void)changeDocumentBackgroundColor:(id)arg1;
- (void)webView:(id)arg1 didWriteSelectionToPasteboard:(id)arg2;
- (BOOL)insertNewline:(id)arg1;
- (BOOL)webView:(id)arg1 doCommandBySelector:(SEL)arg2;
- (void)webViewDidChangeSelection:(id)arg1;
- (id)replaceOldSignatureWithNewSignature:(id)arg1;
- (void)webViewDidChange:(id)arg1;
- (void)mouseUpDidHappen:(id)arg1 inWebView:(id)arg2;
- (void)mouseDownDidHappen:(id)arg1 inWebView:(id)arg2;
- (id)editedEditableElements;
- (void)_doOrUndoEditingInSignatureWithInfo:(id)arg1;
- (void)handleEvent:(id)arg1;
- (void)_stationeryDidFinishLoadingResources:(id)arg1;
- (void)_webViewDidLoadStationery:(id)arg1;
- (void)prepareToRemoveStationery;
- (BOOL)webView:(id)arg1 canInsertFromPasteboard:(id)arg2 forDrag:(BOOL)arg3;
- (void)insertAttributedStringOfAttachments:(id)arg1 allAttachmentsAreOkay:(BOOL)arg2;
- (BOOL)_isOkayToInsertAttachment:(id)arg1;
- (void)_insertAttributedStringOfAttachments:(id)arg1 allAttachmentsAreOkay:(BOOL)arg2;
@property(nonatomic) BOOL shouldAttachFilesAtEnd;
- (BOOL)isOkayToLoadStationery;
- (BOOL)webView:(id)arg1 shouldInsertAttachments:(id)arg2 context:(id)arg3;
- (id)alertForConvertingToRichText;
- (void)setAllowsRichText:(BOOL)arg1;
- (BOOL)allowQuoting;
- (void)setBackEnd:(id)arg1;
- (void)setUp;
- (void)dealloc;
- (void)prepareToGoAway;
@property(readonly) NSArray *insertablePasteboardTypes;

@end
