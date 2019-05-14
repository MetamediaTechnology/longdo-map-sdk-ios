# Longdo Map SDK for iOS
This project contain the library to download for Longdo Map SDK for iOS.

Download all the files and add to your project to start develop application with the SDK.

You can follow the tutorial on how to use Longdo Map SDK for iOS from the link on GitHub.

https://github.com/MetamediaTechnology/longdo-map-demo-ios

## Demo and Tutorial
https://github.com/MetamediaTechnology/longdo-map-demo-ios

## Change log

### Version 3.10.3
* Fix search function for non ASCII keyword.
* Revise `LMPinAnnotation` and `LMEventAnnotation` pin icon.
* Add `complaint` event type.

### Version 3.10.1
* Fix `addLMLayers` when each layer has different alpha value.
* Fix crash when dismiss map view while tag is rendering.

### Version 3.10
* Can customize user location image for pin and arrow.
* Add `addLMLayer` for add layer with alpha channel and showing only in specific zoom.
* Add `removeSourceLayer` for remove custom layer.
* Add `areaOfPolygon` for calulate area of `MKPolygon`.
* Fix `setLanguage` for change language of the map immidiately.
* Fix `removeLMOverlay` in case of cannot remove overlay for some condition.

### Version 3.9.2
* Fix tags not show in some area. (Please see [wiki](https://github.com/MetamediaTechnology/longdo-map-demo-ios/wiki/%5B3.x%5D-การแสดง-Longdo-Tags-บนแผนที่) for changed.)
* Fix offline map not render.
* Fix crashes when try to change language and the map has MKPolygon view.
* Reduce the size of SDK.

### Version 3.9.1
* Fix Longdo style of current location pin.
* Remove automatic set crosshair to center of the map (can use `updateCrosshair` by manual after frame changed instead).
* Fix custom layer that use BBOX3857 may not appear on the map.

### Version 3.9
* HSL format in some camera.
* `getVDOViewFromCameraData:` for get VDO view from camera annotation.
* Add crosshair to show center point of the map.
* Add copyright label when use Longdo layers.

### Version 3.8
* Support Longdo Box.

### Version 3.7
* Has an option for user location's annotation in Longdo Map style.

### Version 3.6.2
* Prevent cache files from being backed up to iCloud/iTunes.

### Version 3.6.1
* Fix tags, events, cameras annotation not show on 1x, 2x scale devices.

### Version 3.6
* Add show event data method.
* Add show camera data method.
* Fix search function for non ASCII keyword.
* Add parameter span, offset, limit for search function.

### Version 3.5
* Fix use custom bounding box tiles in map.

### Version 3.4
* Add function covert from LatLon to UTM.
* Can show multiple layers.

### Version 3.3.1
* Fix offline map in zoom more than 12.

### Version 3.3
* Can get data from url with parameters from current map tile number and map zoom.

### Version 3.2.1
* Can use custom layer with TMS format.

### Version 3.2
* Can use custom layer with bounding box parameter.

### Version 3.1
* Add upside down layer for normal layer.
* Offline layer support. (contact sales@mm.co.th for resource files.)

### Version 3.0.2
* Add blank layer.

### Version 3.0.1
* Premium apikey can use more than 5GB of data.
* Fix cache for map tile images.

### Version 3.0
* Refractor to shorter name.
* Include coordinate parameter to search method.

### Version 3.0 beta 2
* Developer can add their custom layer from url.
* Fix support for 32 bit device.

### Version 3.0 beta 1
* Support Swift 3.
* Search and suggest feature from Longdo Map.
* Based on Apple Mapkit framework.
* Drop support from iOS 7 and earlier.

### Version 2.1
* Full support iOS9 / All data send from ssl.

### Version 2.0.1
* Tiles will resume download after go online immediately.

### Version 2.0.0
* First public release

### Version 1.0.0
* Close beta release

### Version 0.0.0
* Experimental release

## Copyright and license
  * Metamedia Technology © 2005 - now. All Rights Reserved.
  * [Terms of Use](LICENSE.md)
