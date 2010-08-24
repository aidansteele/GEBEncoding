//
//  BEncoding.h
//  
//  This file is part of the BEncoding framework.
//
//  This framework is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This framework is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this framework.  If not, see <http://www.gnu.org/licenses/>.
//
//  Copyright © Nathan Ollerenshaw 2008.
//  Modifications labelled "Glass Echidna" Copyright © Glass Echidna 2009.

#import <Foundation/Foundation.h>
#import "OrderedDictionary.h"

typedef enum {
	GEBEncodedStringType = -1,
	GEBEncodedDataType = 0
} GEBEncodedType;

typedef GEBEncodedType (^GEBEncodedTypeAdvisor)(NSArray *keyStack);

//  BEncoding
//
//  This class is not intended to be instantiated. Its a 'utility' class, and
//  as such you simply call the class methods as required when you need them.
//
//  The BEncoding class can encode and decode data to and from bencoded byte
//  data as defined here: http://wiki.theory.org/BitTorrentSpecification

@interface GEBEncoding : NSObject { }

//  +(NSData *)encodeDataFromObject:(id)object
//
//  This method to returns an NSData object that contains the bencoded
//  representation of the object that you send. You can send complex structures
//  such as an NSDictionary that contains NSArrays, NSNumbers and NSStrings, and
//  the encoder will correctly serialise the data in the expected way.
//
//  Supports NSData, NSString, NSNumber, NSArray and NSDictionary objects.
//
//  NSStrings are encoded as NSData objects as there is no way to differentiate
//  between the two when decoding.
//
//  NSNumbers are encoded and decoded with their longLongValue.
//
//  NSDictionary keys must be NSStrings.

+(NSData *)encodedDataFromObject:(id)object;

//  +(id)objectFromEncodedData:(NSData *)sourceData;
//
//  This method returns an NSObject of the type that is serialised in the bencoded
//  sourceData.
//
//  Bad data should not cause any problems, however if it is unable to deserialise
//  anything from the source, it may return a nil, which you need to check for.

+(id)objectFromEncodedData:(NSData *)sourceData;

+(id)objectFromEncodedData:(NSData *)sourceData withTypeAdvisor:(GEBEncodedTypeAdvisor)typeAdvisor;

@end
