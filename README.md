# RP2040_Bootloader
This is meant to be short and sweet. (May be a little dangerous.)

After having a discussion [here](https://forums.raspberrypi.com/viewtopic.php?t=352931), I decided that this will be an individual project with a take it or leave it approach. Boot loaders on the RP2040 someday could become more involved in terms of support long term. (This does not apply to projects tied to specific SDK versions.) If this project was finished and a change occured to the SDK which required a change this project said new version of the SDK may never gain support. Therefore this project is basically pretentious and vain. However others may find the idea within it interesting, which is the only reason it is still public. (I may still hide or remove it.)

Summary of issue (This is a hypothetical.): The ROM boot loader could create requirement for a different SDK. This would create the SDK as a dependency in the future for different chips. (Not likely to be an issue but possible.) Should this project lose active support, this could become problematic. The issue is the SDK upgrade will not be available. Also consumers of this project will need to know which version to use for the specific hardware configurations. 

In such discussion it was also considered that this project currently uses the incorrect procedure. Project is not finished or tested and may never be. Original purpose was lost and effort was put into something else.
