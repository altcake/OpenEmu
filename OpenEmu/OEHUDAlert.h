/*
 Copyright (c) 2017, OpenEmu Team
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of the OpenEmu Team nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY OpenEmu Team ''AS IS'' AND ANY
 EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL OpenEmu Team BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

@import Cocoa;

@class OEProgressIndicator;
@class OEHUDAlert;
@class OEButton;
@class OETextField;

NS_ASSUME_NONNULL_BEGIN

typedef void (^OEAlertCompletionHandler)(OEHUDAlert *alert, NSModalResponse result);

@interface OEHUDAlert : NSObject

+ (OEHUDAlert *)alertWithMessageText:(nullable NSString *)msgText
                       defaultButton:(nullable NSString *)defaultButtonLabel
                     alternateButton:(nullable NSString *)alternateButtonLabel;

#pragma mark -

- (NSModalResponse)runModal;
- (void)performBlockInModalSession:(void(^)(void))block;
- (void)closeWithResult:(NSInteger)result;

@property (readonly) NSModalResponse result;
@property NSWindow *window;

#pragma mark - Buttons

@property (readonly) NSButton *defaultButton;
@property (readonly) NSButton *alternateButton;
@property (readonly) NSButton *otherButton;

@property (readonly) NSTextField *messageTextView;
@property (readonly) NSTextField *headlineTextView;

@property (copy) NSString *stringValue;
@property (copy) NSString *otherStringValue;
@property (copy) NSString *inputLabelText;
@property (copy) NSString *otherInputLabelText;
@property (copy, null_resettable) NSString *defaultButtonTitle;
@property (copy, null_resettable) NSString *alternateButtonTitle;
@property (copy, null_resettable) NSString *otherButtonTitle;
@property (copy) NSString *title;
@property (copy, null_resettable) NSString *messageText;
@property (copy, null_resettable) NSString *headlineText;

#pragma mark - Input Field

@property (readonly) NSTextField *inputLabelView;
@property (readonly) NSTextField *otherInputLabelView;
@property (readonly) NSTextField *inputField;
@property (readonly) NSTextField *otherInputField;
@property (nonatomic) BOOL showsInputField;
@property (nonatomic) BOOL showsOtherInputField;
@property NSInteger inputLimit;

#pragma mark - Progress Bar

@property (nonatomic) BOOL showsProgressbar;
@property (readonly) NSProgressIndicator *progressbar;

@property double progress;

#pragma mark - Button Actions

- (void)setDefaultButtonAction:(SEL)sel andTarget:(id)target;
- (void)setAlternateButtonAction:(SEL)sel andTarget:(id)target;
- (void)setOtherButtonAction:(SEL)sel andTarget:(id)target;
- (void)buttonAction:(id)sender;

#pragma mark - Callbacks

@property (weak) id target;
@property SEL callback;
@property (copy) OEAlertCompletionHandler callbackHandler;

#pragma mark - Suppression Button

- (void)showSuppressionButtonForUDKey:(NSString *)key;

@property (nonatomic) BOOL showsSuppressionButton;
@property (readonly) NSButton *suppressionButton;
/// Default is YES meaning follow up alerts will not be suppressed if user clicked cancel.
@property BOOL suppressOnDefaultReturnOnly;
@property (copy) NSString *suppressionUDKey;
/// Default is "Do not ask me again", can be changed (e.g. if alert is too small).
@property (copy) NSString *suppressionLabelText;

@end

NS_ASSUME_NONNULL_END
