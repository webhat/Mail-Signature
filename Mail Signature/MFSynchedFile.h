/*
 * Copyright (c) 2015 Daniël W. Crompton. All rights reserved.
 *
 *     This file is part of Mail Signature.
 *
 * Mail Signature is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 
 * Mail Signature is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License
 * along with Mail Signature.  If not, see <http://www.gnu.org/licenses/>.
 */

@interface MFSyncedFile : NSObject <NSFilePresenter>
{
    NSURL *_cloudURL;
    id _cloudURLLock;
    NSURL *_url;
    id _conflictResolver;
    unsigned long long _syncState;
}

+ (id)_metadataURL;
+ (id)_metadata;
+ (id)_currentiCloudAccount;
+ (void)stopPersistingSyncedFileForURL:(id)arg1;
+ (id)syncedFileForURL:(id)arg1 withConflictResolver:(id)arg2;
+ (void)initialize;
@property unsigned long long syncState; // @synthesize syncState=_syncState;
@property(copy) id conflictResolver; // @synthesize conflictResolver=_conflictResolver;
@property(readonly) NSURL *URL; // @synthesize URL=_url;
- (void)_handleIdentityChange:(id)arg1;
- (void)_resolveConflicts;
- (void)_setCloudURL;
@property(readonly) NSURL *cloudURL;
- (id)_ubiquitousFileName;
- (id)_ubiquitousFileURL;
- (BOOL)_fileExistsInCloud;
- (BOOL)_writeDataToCloud:(id)arg1 options:(unsigned long long)arg2 error:(id *)arg3;
- (BOOL)_syncWithCloudPostNotification:(BOOL)arg1 error:(id *)arg2;
- (BOOL)synchronouslyWritePlist:(id)arg1 options:(unsigned long long)arg2 error:(id *)arg3;
- (id)synchronouslyReadPlistWithOptions:(unsigned long long)arg1 error:(id *)arg2;
- (BOOL)_deleteFileLocallyPostingNotification:(BOOL)arg1 error:(id *)arg2;
- (void)deleteFile;
- (id)_readPlistWithOptions:(unsigned long long)arg1 error:(id *)arg2;
- (id)readPlistWithOptions:(unsigned long long)arg1;
- (void)writePlist:(id)arg1 options:(unsigned long long)arg2;
- (id)readDataWithOptions:(unsigned long long)arg1;
- (BOOL)_writeDataLocally:(id)arg1 options:(unsigned long long)arg2 setMetadata:(BOOL)arg3 postNotification:(BOOL)arg4 error:(id *)arg5;
- (BOOL)_writeDataAfterResolvingConflict:(id)arg1 options:(unsigned long long)arg2 error:(id *)arg3;
- (BOOL)_writeData:(id)arg1 options:(unsigned long long)arg2 error:(id *)arg3;
- (void)writeData:(id)arg1 options:(unsigned long long)arg2;
- (void)_clearMetadata;
- (BOOL)_signedInState;
- (void)_setiCloudAccount;
- (id)_iCloudAccount;
- (void)presentedItemDidResolveConflictVersion:(id)arg1;
- (void)presentedItemDidMoveToURL:(id)arg1;
- (void)presentedItemDidGainVersion:(id)arg1;
- (void)presentedItemDidChange;
- (void)accommodatePresentedItemDeletionWithCompletionHandler:(id)arg1;
@property(readonly) NSOperationQueue *presentedItemOperationQueue;
@property(readonly) NSURL *presentedItemURL;
- (void)dealloc;
- (id)init;
- (id)initWithURL:(id)arg1 withConflictResolver:(id)arg2;

// Remaining properties
@property(readonly) NSURL *primaryPresentedItemURL;

@end
