/*

 Copyright 2017 iMobile3, LLC. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, is permitted provided that adherence to the following
 conditions is maintained. If you do not agree with these terms,
 please do not use, install, modify or redistribute this software.

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY IMOBILE3, LLC "AS IS" AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL IMOBILE3, LLC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */

#import <Foundation/Foundation.h>

/**
 Used for configuring an apple pay transaction with CCCPaymentController.
 */
@interface CCCPaymentRequest : NSObject

/**
 The merchant ID you've registered with apple for accepting ApplePay transactions.

  **REQUIRED**
 */
@property (nonatomic, copy) NSString * _Nullable applePayMerchantID;

/**
 The total amount for the transaction.

 * *REQUIRED if paymentSummaryItems is not provided*
 */
@property (nonatomic, copy) NSDecimalNumber * _Nullable total;

/**
 Your company name that will appear in the apple pay label as "PAY <applePayCompanyName> <total>"
 
 * *REQUIRED if paymentSummaryItems is not provided*
 
 As required by apple, this label should reference who the user is paying this total amount to.
 If this is not provided you'll not see the apple pay option in CCCAccountListViewController.
 */
@property (nonatomic, copy) NSString * _Nullable companyName;

/**
 An optional list of summary items for apple pay.
 
 If provided, this list of items will appear in the apple pay receipt instead of the single total line item with companyName. This should be an array of PKPaymentSummaryItem with the final item containing the total amount as provided above. This will be confirmed to be an array of PKPaymentSummaryItem and will default to total and companyName if it's anything else.
 */
@property (nonatomic, copy) NSArray * _Nullable paymentSummaryItems;

/**
 Optional data that can be passed for the transaction.

 Typically this should contain an order number or transaction id base64 string encoded.
 */
@property (nonatomic, copy) NSData * _Nullable additionalData;

@end
