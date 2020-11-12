# Longdo Map SDK for iOS
This project contains a library to download Longdo Map SDK for iOS.

Download all files and then add them into your project to start application development with our SDK.

For more information, you can follow our tutorial to learn how to use Longdo Map SDK for iOS as the link below.

https://github.com/MetamediaTechnology/longdo-map-demo-ios

## Demo and Tutorial
https://github.com/MetamediaTechnology/longdo-map-demo-ios

## Change log

### Version 3.15
* Improve performance when load map tile images from server.

### Version 3.14
* Add rain layer.
* Use xcframework. (Please use Xcode 11 or above.)

### Version 3.13
* Improve performance when load map tile images from server.

### Version 3.12.4
* Improve performance when load map tile images from server.
* Fix custom layer that using custom image format.

### Version 3.12.3
* Improve performance when load map tile images from server.

### Version 3.12.2
* Support Mac Catalyst. (Manually import xcframework.)
* Update deprecated `UIWebview` to `WKWebView`.
* Fix an issue when user changes map's zoom to level 20 or more.
* Revise event pin appearance for each zoom level.

### Version 3.12.1
* Remove "User Interface Style" property in Info.plist.

### Version 3.12
* Add routing function.
* Revise functions related to search and suggestion.
* Allow to customize an image, alpha value, and visible range of specified tag.
* Fix an issue related to no-key-required layers which cannot show normally.
* Fix an issue that tags may not show on map when call API from Longdo Box.
* Fix tag appearance when change zoom level or map layer.
* Fix to clear event/camera annotations when hide event/camera.
* ~Fix an issue that map tile does not stop blinking on the map.~
* Fix an issue that overlaid geometry cannot display properly when add new layer after geometry.

### Version 3.11.1
* Improve a logic to check API key when swap online and offline mode.
* Switch event pin language to Thai if English is not available.
* Fix crashing issue when use invalid tile URL.
* Fix an issue that `zoomLevel` may return wrong value.
* Fix an issue related to traffic layer that it may be removed unexpectedly after remove multiple overlays.

### Version 3.11
* Convert function `showEvents` and `removeEvents` to boolean property `showsEvents`.
* Convert function `showCameras` and `removeCameras` to boolean property `showsCameras`.
* Convert function `setZoomLevel:` and `getZoomLevel` to float property `zoomLevel`.
* Support inspector in interface builder for some class properties of `LongdoMapView`.
* Allow event language in `LMEventAnnotation` to align with changed map language.
* Add new feature to automatically update Traffic layer and event pins every 180 seconds.

### Version 3.10.3
* Fix search function for non-ASCII keyword.
* Revise pin icon `LMPinAnnotation` and `LMEventAnnotation`.
* Add event type `complaint`.

### Version 3.10.1
* Fix `addLMLayers` when each layer has different alpha value.
* Fix crashing issue when dismiss map view while tag is rendering.

### Version 3.10
* Allow to customize image of user location for pin and arrow.
* Add function `addLMLayer` for adding layer with alpha channel and defining visibility in specific zoom level.
* Add function `removeSourceLayer` for removing custom layer.
* Add function `areaOfPolygon` for calulating area of `MKPolygon`.
* Fix function `setLanguage` for changing map language immediately.
* Fix function `removeLMOverlay` that cannot remove overlay for some conditions.

### Version 3.9.2
* Fix tags that cannot display in some areas (please see [wiki](https://github.com/MetamediaTechnology/longdo-map-demo-ios/wiki/%5B3.x%5D-การแสดง-Longdo-Tags-บนแผนที่) for change).
* Fix rendering offline map.
* Fix crashing issue when try to change language and the map has MKPolygon view.
* Reduce SDK size.

### Version 3.9.1
* Fix Longdo style for current location pin.
* Remove automatic relocation of crosshairs (however `updateCrosshair` can be relocated to center of map manually).
* Fix custom layer that using BBOX3857 may not appear on the map.

### Version 3.9
* Support cameras in format of HSL.
* Add function `getVDOViewFromCameraData:` for retrieving VDO view from camera annotation.
* Add crosshairs to show center point of the map.
* Add copyright label when use Longdo layers.

### Version 3.8
* Support Longdo Box.

### Version 3.7
* Add new option for user location's annotation in Longdo Map style.

### Version 3.6.2
* Prevent cache files from being backed up to iCloud/iTunes.

### Version 3.6.1
* Fix tags, events, and cameras annotation that cannot show on 1x- and 2x-scale devices.

### Version 3.6
* Add new method to show event data.
* Add new method to show camera data.
* Fix search function for non-ASCII keyword.
* Add parameters i.e. span, offset, limit for search function.

### Version 3.5
* Fix an issue related to custom bounding box tiles on map.

### Version 3.4
* Add new function for coverting LatLon to UTM.
* Add new feature to show multiple layers.

### Version 3.3.1
* Fix offline map in case of zoom level more than 12.

### Version 3.3
* Allow to retrieve data from URL with current map tile number and zoom level as parameters.

### Version 3.2.1
* Allow to use custom layer with TMS format.

### Version 3.2
* Allow to use custom layer with bounding box parameter.

### Version 3.1
* Add upside down layer for normal layer.
* Support offline layer (please contact sales@mm.co.th for resource files).

### Version 3.0.2
* Add blank layer.

### Version 3.0.1
* Enable premium API key to use data more than 5 GB.
* Fix cache for map tile images.

### Version 3.0
* Apply code refactoring for shorter name.
* Modify search method to include coordinate parameter.

### Version 3.0 beta 2
* Allow programmatically to add their custom layer via URL.
* Support 32-bit device.

### Version 3.0 beta 1
* Support Swift 3.
* Add search and suggest feature from Longdo Map.
* Revise development based on Apple Mapkit framework.
* Discontinue to support iOS 7 and earlier.

### Version 2.1
* Fully support iOS 9 therefore all data is required to send via SSL.

### Version 2.0.1
* Enable to immediately resume downloading map tiles after network is available.

### Version 2.0.0
* Officially launch.

### Version 1.0.0
* Release close-beta version.

### Version 0.0.0
* Release experimental version.

## Copyright and license
  * Metamedia Technology © 2005 - now. All Rights Reserved.
  * [Terms of Use](LICENSE.md)
