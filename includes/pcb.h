#include "types.h"

#pragma once
class pcb {
public:
    osp2023::id_type id;
    osp2023::time_type burst_time;
    osp2023::time_type time_used;
    osp2023::time_type total_wait_time;


public:
    pcb() : id(osp2023::id_not_set), burst_time(osp2023::time_not_set), time_used(0), total_wait_time(0) {}

    void set_id(osp2023::id_type new_id) {
        id = new_id;
    }

    osp2023::id_type get_id() const {
        return id;
    }

    void set_burst_time(osp2023::time_type new_burst_time) {
        burst_time = new_burst_time;
    }

    osp2023::time_type get_burst_time() const {
        return burst_time;
    }

    static constexpr osp2023::time_type MAX_DURATION = 100;
    static constexpr osp2023::time_type MIN_DURATION = 10;
};



