@interface HeadersEditor : NSObject <AccountStatusDataSourceDelegate, NSUserInterfaceValidations, NSWindowDelegate>
{
    DocumentEditor *_documentEditor;
    ComposeHeaderView *_composeHeaderView;
    NSPopUpButton *_fromPopup;
    NSPopUpButton *_signaturePopup;
    NSPopUpButton *_priorityPopup;
    NSSegmentedControl *_signButton;
    NSSegmentedControl *_encryptButton;
    AccountStatusDataSource *_deliveryASDS;
    NSPopUpButton *_deliveryPopUp;
    NSTextField *_subjectField;
    NSMutableArray *_accessoryViewOwners;
    BOOL _hasChanges;
    BOOL _registeredForAnimationObservation;
    MUIAddressField *_toField;
    MUIAddressField *_ccField;
    MUIAddressField *_bccField;
    MUIAddressField *_replyToField;
    NSTextField *_toTitle;
    NSTextField *_ccTitle;
    NSTextField *_bccTitle;
    NSTextField *_replyToTitle;
}

+ (id)keyPathsForValuesAffectingDeliveryAccount;
@property(nonatomic) BOOL registeredForAnimationObservation; // @synthesize registeredForAnimationObservation=_registeredForAnimationObservation;
@property BOOL hasChanges; // @synthesize hasChanges=_hasChanges;
@property(nonatomic) NSTextField *replyToTitle; // @synthesize replyToTitle=_replyToTitle;
@property(nonatomic) NSTextField *bccTitle; // @synthesize bccTitle=_bccTitle;
@property(nonatomic) NSTextField *ccTitle; // @synthesize ccTitle=_ccTitle;
@property(nonatomic) NSTextField *toTitle; // @synthesize toTitle=_toTitle;
@property(retain, nonatomic) MUIAddressField *replyToField; // @synthesize replyToField=_replyToField;
@property(retain, nonatomic) MUIAddressField *bccField; // @synthesize bccField=_bccField;
@property(retain, nonatomic) MUIAddressField *ccField; // @synthesize ccField=_ccField;
@property(retain, nonatomic) MUIAddressField *toField; // @synthesize toField=_toField;
- (id)_newSenderMarkupStringIncludeBrackets:(BOOL)arg1;
- (BOOL)validateMenuItem:(id)arg1;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (void)dealloc;
- (void)prepareToCloseWindow;
- (void)_clearFieldIfHidden:(id)arg1;
- (void)addReplyToHeader:(id)arg1;
- (void)addBccHeader:(id)arg1;
- (void)addCcHeader:(id)arg1;
- (BOOL)headerCustomizationIsInProgress;
- (void)composeHeaderViewDidEndCustomization:(id)arg1;
- (void)composeHeaderViewWillBeginCustomization:(id)arg1;
- (void)changeSignature:(id)arg1;
- (void)editSignatures:(id)arg1;
- (void)_updateEncryptButtonInBackground;
- (void)securityControlChanged:(id)arg1;
- (void)setMessagePriority:(id)arg1;
- (void)changeFromHeader:(id)arg1;
- (void)changeHeaderField:(id)arg1;
- (void)accountStatusDidChange:(id)arg1;
- (id)mailAccount;
- (void)setDeliveryAccount:(id)arg1;
- (void)_setDynamicDeliveryAccountForAccount:(id)arg1;
- (id)deliveryAccount;
- (void)setSelectedAccount:(id)arg1;
- (void)toggleAccountLock:(id)arg1;
- (void)editServerList:(id)arg1 selectedAccount:(id)arg2;
- (BOOL)isOkayToSaveMessage:(id)arg1;
- (BOOL)canSignFromAnyAccount;
- (BOOL)messageHasRecipients;
- (BOOL)messageIsToBeEncrypted;
- (BOOL)messageIsToBeSigned;
- (void)changeSignatureFrom:(id)arg1 to:(id)arg2;
- (void)turnOffEncryption;
- (void)setCheckGrammarWithSpelling:(BOOL)arg1;
- (void)setInlineSpellCheckingEnabled:(BOOL)arg1;
- (void)appendAddresses:(id)arg1 toHeader:(id)arg2;
- (void)setHeaders:(id)arg1;
- (BOOL)_headerFieldIsNonEmpty:(id)arg1;
- (void)_addressFieldChanged;
- (void)_subjectChanged;
- (void)_textFieldBeganOrEndedEditing:(id)arg1;
- (void)loadHeadersFromBackEnd:(id)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (id)_headerKeyForView:(id)arg1;
- (id)fieldForHeader:(id)arg1;
- (void)_configureTextField:(id)arg1 isAddressField:(BOOL)arg2;
- (void)_setupField:(id)arg1 withAddressesForKey:(id)arg2 visibilityBlock:(CDUnknownBlockType)arg3;
- (void)_setupAddressField:(id)arg1;
- (void)webViewDidLoadStationery:(id)arg1;
- (void)updateCcOrBccMyselfFieldWithSender:(id)arg1 oldSender:(id)arg2;
- (double)deliveryPopUpSizeToFitWidth;
- (void)_configureDeliveryPopupButton;
- (void)updateDeliveryAccountControl:(id)arg1;
- (void)updateSignatureControlOverridingExistingSignature:(BOOL)arg1;
- (void)_updateFromAndSignatureControls:(id)arg1;
- (void)_updateEncryptButtonToolTip;
- (void)_toggleEncrypButtonImages;
- (void)_updateSignButtonToolTip;
- (void)_toggleSignButtonImages;
- (void)_updateSecurityStateInBackgroundForRecipients:(id)arg1 sender:(id)arg2;
- (void)updateSecurityControls;
- (void)updatePriorityPopUpMakeActive:(BOOL)arg1;
- (void)windowDidResignKey:(id)arg1;
- (void)windowDidBecomeKey:(id)arg1;
- (void)_accountInfoDidChange:(id)arg1;
- (void)_mailAccountsDidChange:(id)arg1;
- (void)composePrefsChanged;
- (void)initializePriorityPopUp;
- (void)configureButtonsAndPopUps;
- (void)setAGoodFirstResponder;
- (void)finishSetUp;
- (void)setUpFieldsAndButtons;
- (void)awakeFromNib;

@end
