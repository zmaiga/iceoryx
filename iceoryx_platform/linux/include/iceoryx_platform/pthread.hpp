// Copyright (c) 2020 by Robert Bosch GmbH. All rights reserved.
// Copyright (c) 2021 - 2022 by Apex.AI Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0
#ifndef IOX_HOOFS_LINUX_PLATFORM_PTHREAD_HPP
#define IOX_HOOFS_LINUX_PLATFORM_PTHREAD_HPP

#include <pthread.h>

#define IOX_PTHREAD_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER
#define IOX_PTHREAD_PROCESS_SHARED PTHREAD_PROCESS_SHARED
#define IOX_PTHREAD_PROCESS_PRIVATE PTHREAD_PROCESS_PRIVATE
#define IOX_PTHREAD_MUTEX_RECURSIVE PTHREAD_MUTEX_RECURSIVE
#define IOX_PTHREAD_MUTEX_NORMAL PTHREAD_MUTEX_NORMAL
#define IOX_PTHREAD_MUTEX_ERRORCHECK PTHREAD_MUTEX_ERRORCHECK
#define IOX_PTHREAD_MUTEX_DEFAULT PTHREAD_MUTEX_DEFAULT

#define IOX_PTHREAD_MUTEX_STALLED PTHREAD_MUTEX_STALLED
#define IOX_PTHREAD_MUTEX_ROBUST PTHREAD_MUTEX_ROBUST

#define IOX_PTHREAD_PRIO_NONE PTHREAD_PRIO_NONE
#define IOX_PTHREAD_PRIO_INHERIT PTHREAD_PRIO_INHERIT
#define IOX_PTHREAD_PRIO_PROTECT PTHREAD_PRIO_PROTECT

using iox_pthread_mutex_t = pthread_mutex_t;
using iox_pthread_mutexattr_t = pthread_mutexattr_t;

inline int iox_pthread_mutexattr_init(iox_pthread_mutexattr_t* attr)
{
    return pthread_mutexattr_init(attr);
}

inline int iox_pthread_mutexattr_destroy(iox_pthread_mutexattr_t* attr)
{
    return pthread_mutexattr_destroy(attr);
}

inline int iox_pthread_mutexattr_setpshared(iox_pthread_mutexattr_t* attr, int pshared)
{
    return pthread_mutexattr_setpshared(attr, pshared);
}

inline int iox_pthread_mutexattr_settype(iox_pthread_mutexattr_t* attr, int type)
{
    return pthread_mutexattr_settype(attr, type);
}

inline int iox_pthread_mutexattr_setprotocol(iox_pthread_mutexattr_t* attr, int protocol)
{
    return pthread_mutexattr_setprotocol(attr, protocol);
}

inline int iox_pthread_mutexattr_setrobust(iox_pthread_mutexattr_t* attr, int robustness)
{
    return pthread_mutexattr_setrobust(attr, robustness);
}

inline int iox_pthread_mutexattr_setprioceiling(iox_pthread_mutexattr_t* attr, int prioceiling)
{
    return pthread_mutexattr_setprioceiling(attr, prioceiling);
}

inline int iox_pthread_mutex_init(iox_pthread_mutex_t* mutex, const iox_pthread_mutexattr_t* attr)
{
    return pthread_mutex_init(mutex, attr);
}

inline int iox_pthread_mutex_destroy(iox_pthread_mutex_t* mutex)
{
    return pthread_mutex_destroy(mutex);
}

inline int iox_pthread_mutex_lock(iox_pthread_mutex_t* mutex)
{
    return pthread_mutex_lock(mutex);
}

inline int iox_pthread_mutex_trylock(iox_pthread_mutex_t* mutex)
{
    return pthread_mutex_trylock(mutex);
}

inline int iox_pthread_mutex_unlock(iox_pthread_mutex_t* mutex)
{
    return pthread_mutex_unlock(mutex);
}

inline int iox_pthread_mutex_consistent(iox_pthread_mutex_t* mutex)
{
    return pthread_mutex_consistent(mutex);
}

using iox_pthread_t = pthread_t;
using iox_pthread_attr_t = pthread_attr_t;

inline int iox_pthread_setname_np(iox_pthread_t thread, const char* name)
{
    return pthread_setname_np(thread, name);
}

inline int iox_pthread_getname_np(iox_pthread_t thread, char* name, size_t len)
{
    return pthread_getname_np(thread, name, len);
}

inline int
iox_pthread_create(iox_pthread_t* thread, const iox_pthread_attr_t* attr, void* (*start_routine)(void*), void* arg)
{
    return pthread_create(thread, attr, start_routine, arg);
}

inline int iox_pthread_join(iox_pthread_t thread, void** retval)
{
    return pthread_join(thread, retval);
}

inline iox_pthread_t iox_pthread_self()
{
    return pthread_self();
}

#endif // IOX_HOOFS_LINUX_PLATFORM_PTHREAD_HPP
