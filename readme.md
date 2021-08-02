# 機械雲計費RESTful API測試工具
#

該測試工具參考以下swagger
- http://35.72.85.136:8081/swagger/index.html?file=doc/metering.yaml#/Metering


提供兩種計費方式的API測試:
- 按次收費
- 按時收費

## 按次收費
POST 
http://{IP}:{Port}/dw/metering/count/raw

Payload內容範例 (json格式)
```sh
{
  "deviceId": "E3B3D13ADAB443D64E800CA88B06FC8F",
  "appName": "iCAM",
  "appId": "8f14e45fceea167a5a36dedd4bea2543",
  "userId": "paul@itri.org.tw",
  "type": "count",
  "countName": "APInumber",
  "count": 100
}
```
> 注意: 上述的appId、appName、type是有對應關係的, `不能亂填`
> 如appName 'iCAM' 所對應的 appId為 '8f14e45fceea167a5a36dedd4bea2543',
> 且appName 'iCAM'當初登記的收費方式為 '按次收費'("type": "count"), 
> 詳細資訊請上機械雲管理平台查看



## 按時收費
POST 
http://{IP}:{Port}/dw/metering/time/raw

Payload內容範例 (json格式)
```sh
{
  "deviceId": "E3B3D13ADAB443D64E800CA88B06FC8F",
  "appName": "Notepad",
  "appId": "notepadsampleapp",
  "userId": "paul@itri.org.tw",
  "type": "time",
  "time": 3600
}
```
> Notepad這個app使用了3600秒
> appName, appId, type 綁定關係請上機械雲管理平台查看

