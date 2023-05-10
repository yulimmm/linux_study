### Information
+ input: RTSP
+ ouput: RTSP
+ Edit *source1_csi_dec_infer_resent_int8.txt* and *source8_1080p_dec_infer-resnet_tracker_tiled_display_fp16_nano.txt* 

### File location
``` 
$ cd /opt/nvidia/deepstream/deepstream-6.0/samples/configs/deepstream-app
``` 

### Run
``` 
$ deepstream-app -c /opt/nvidia/deepstream/deepstream-6.0/samples/configs/deepstream-app/rtsp_test.txt
``` 

### Go to VLC
network stream example: 
``` 
rtsp://<PC installed deepstream IP>:8554/ds-test
``` 
