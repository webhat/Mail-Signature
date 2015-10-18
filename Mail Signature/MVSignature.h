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

#import "MFSynchedFile.h"


@interface Signature : NSObject <NSCopying>
{
    NSString *_uniqueId;
    NSString *_name;
    NSData *_webArchiveData;
    BOOL _isRich;
    BOOL _isSavedAsRich;
    BOOL _isDirty;
    MFSyncedFile *_syncedFile;
}

- (id)syncedFile;
- (id)signaturePath;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)arg1;
- (BOOL)isRich;
- (void)setIsRich:(BOOL)arg1;
- (void)setWebArchive:(id)arg1;
- (id)webArchive;
- (id)_sanitizeSignatureFileData:(id)arg1;
- (id)webArchiveData;
- (void)reloadFromDisk;
- (void)setName:(id)arg1;
- (id)name;
- (id)uniqueId;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)dictionaryRepresentation;
- (void)removeContentFromDisk;
- (BOOL)saveContentToDisk;
- (void)dealloc;
- (id)initWithDictionary:(id)arg1;
- (id)initWithName:(id)arg1;
- (id)initWithName:(id)arg1 uniqueId:(id)arg2;
- (id)objectSpecifier;
- (void)setSignatureContents:(id)arg1;
- (id)signatureContents;
- (void)setSignatureName:(id)arg1;
- (id)signatureName;

@end
