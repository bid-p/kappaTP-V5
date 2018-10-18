#include "main.h"

namespace lcd {
    lv_obj_t *blue_close;
    lv_obj_t *red_close;
    lv_obj_t *blue_far;
    lv_obj_t *red_far;
    lv_obj_t *curr_sel_label;
    okapi::Logger *logger = okapi::Logger::instance();

    tAutons currAutonState = eblueClose;


    void selectAutonLog() {
        switch (currAutonState) {
            case eblueClose:
                logger->debug("Blue Close Selected");
                break;
            case eblueFar:
                logger->debug("Blue Far Selected");
                break;
            case eredClose:
                logger->debug("Red Close Selected");
                break;
            case eredFar:
                logger->debug("Red Far Selected");
                break;
        }
    }

    lv_res_t selectBlueClose(lv_obj_t *button) {
        lv_label_set_text(curr_sel_label, "Blue Close");
        currAutonState = eblueClose;
        selectAutonLog();
    }

    lv_res_t selectRedClose(lv_obj_t *button) {
        lv_label_set_text(curr_sel_label, "Red Close");
        currAutonState = eredClose;
        selectAutonLog();
    }

    lv_res_t selectBlueFar(lv_obj_t *button) {
        lv_label_set_text(curr_sel_label, "Blue Far");
        currAutonState = eblueFar;
        selectAutonLog();
    }

    lv_res_t selectRedFar(lv_obj_t *button) {
        lv_label_set_text(curr_sel_label, "Red Far");
        currAutonState = eredFar;
        selectAutonLog();
    }

    void initButtons() {
        curr_sel_label = lv_label_create(lv_scr_act(), NULL);
        lv_label_set_text(curr_sel_label, "");
        lv_obj_align(curr_sel_label, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 20);

        blue_close = lv_btn_create(lv_scr_act(), NULL);
        lv_obj_align(blue_close, lv_scr_act(), LV_ALIGN_IN_TOP_RIGHT, 10, 0);
        lv_obj_t *blueCloseLabel = lv_label_create(blue_close, NULL);
        lv_label_set_text(blueCloseLabel, "Blue Close");
        lv_cont_set_fit(blue_close, true, true);

        red_close = lv_btn_create(lv_scr_act(), NULL);
        lv_obj_align(red_close, lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, 10, 0);
        lv_obj_t *redCloseLabel = lv_label_create(red_close, NULL);
        lv_label_set_text(redCloseLabel, "Red Close");
        lv_cont_set_fit(red_close, true, true);

        blue_far = lv_btn_create(lv_scr_act(), NULL);
        lv_obj_align(blue_far, lv_scr_act(), LV_ALIGN_IN_BOTTOM_RIGHT, 10, 0);
        lv_obj_t *blueFarLabel = lv_label_create(blue_far, NULL);
        lv_label_set_text(blueFarLabel, "Blue Far");
        lv_cont_set_fit(blue_far, true, true);

        red_far = lv_btn_create(lv_scr_act(), NULL);
        lv_obj_align(red_far, lv_scr_act(), LV_ALIGN_IN_BOTTOM_LEFT, 10, 0);
        lv_obj_t *redFarLabel = lv_label_create(red_far, NULL);
        lv_label_set_text(redFarLabel, "Red Far");
        lv_cont_set_fit(red_far, true, true);

        okapi::Logger::initialize(
            okapi::TimeUtilFactory::create().getTimer(),
            "/ser/sout", // output to the PROS terminal over standard out
            okapi::Logger::LogLevel::debug // most verbose log level
        );

        lv_btn_set_action(blue_close, LV_BTN_ACTION_PR, selectBlueClose);
        lv_btn_set_action(red_close, LV_BTN_ACTION_PR, selectRedClose);
        lv_btn_set_action(blue_far, LV_BTN_ACTION_PR, selectBlueFar);
        lv_btn_set_action(red_far, LV_BTN_ACTION_PR, selectRedFar);
    }

    void runAuton() {
        switch (currAutonState) {
            case eblueClose:
                logger->debug("Running Blue Close");
                blueCloseAuto();
                break;
            case eblueFar:
                blueFarAuto();
                logger->debug("Running Blue Far");
                break;
            case eredClose:
                redCloseAuto();
                logger->debug("Running Red Close");
                break;
            case eredFar:
                redFarAuto();
                logger->debug("Running Red Far");
                break;
        }
    }
}