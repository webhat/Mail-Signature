@interface ComposeViewController : NSViewController <AccountStatusDataSourceDelegate, MCActivityTarget, NSUserInterfaceValidations>
{
    id <ComposeViewControllerDelegate> _delegate;
    NSOperationQueue *_workerQueue;
    AccountStatusDataSource *_deliveryAccountStatusDataSource;
    NewDeliveryFailure *_deliveryFailure;
}

@property(retain, nonatomic) NewDeliveryFailure *deliveryFailure; // @synthesize deliveryFailure=_deliveryFailure;
@property(retain, nonatomic) AccountStatusDataSource *deliveryAccountStatusDataSource; // @synthesize deliveryAccountStatusDataSource=_deliveryAccountStatusDataSource;
@property(readonly) NSOperationQueue *workerQueue; // @synthesize workerQueue=_workerQueue;
@property(nonatomic) id <ComposeViewControllerDelegate> delegate; // @synthesize delegate=_delegate;
- (BOOL)_alwaysCcOrBccMyself;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (void)_updateActiveField;
- (void)addAttachments:(id)arg1;
- (void)discard;
- (void)saveMessageToDrafts:(id)arg1;
- (void)finishEditing;
- (void)reportDeliveryFailure:(id)arg1;
- (void)_didAppendMessageToOutboxWithResult:(int)arg1 error:(id)arg2;
- (void)_saveRecipients;
- (void)_appendMessageToOutboxInBackground:(id)arg1;
- (void)sendMessageAfterChecking:(id)arg1;
- (void)send:(id)arg1;
- (void)_updateSendButton;
- (BOOL)_allowSend;
- (void)_updateSecurityControls;
- (void)_updateShowCcBccFrom;
- (id)_dynamicDeliveryAccountForAccount:(id)arg1;
- (void)_updateDeliveryPopupWithAccount:(id)arg1;
- (void)_updateComposeViewWithFrom:(id)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)isSignedChanged:(id)arg1;
- (void)isEncryptedChanged:(id)arg1;
- (void)signatureChanged:(id)arg1;
- (void)priorityChanged:(id)arg1;
- (void)subjectChanged:(id)arg1;
- (void)setDeliveryAccount:(id)arg1;
- (void)_setDeliveryAccountWithFromAccount:(id)arg1;
- (void)setSelectedAccount:(id)arg1;
- (void)fromChanged:(id)arg1;
- (void)_replyToChanged:(id)arg1;
- (void)_bccChanged:(id)arg1;
- (void)_ccChanged:(id)arg1;
- (void)_toChanged:(id)arg1;
- (void)awakeFromNib;
- (void)setRepresentedObject:(id)arg1;
- (id)representedObject;
- (id)view;
- (id)nibName;
- (void)dealloc;
- (void)_composeViewControllerCommonInit;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (id)init;

@end
