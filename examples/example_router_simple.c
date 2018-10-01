/*                         _
 *   ___  __ _  __ _ _   _(_)
 *  / __|/ _` |/ _` | | | | |
 *  \__ \ (_| | (_| | |_| | |
 *  |___/\__,_|\__, |\__,_|_|
 *             |___/
 *
 *   –– an ideal C library to develop cross-platform HTTP servers.
 *
 * Copyright (c) 2016-2018 Silvio Clecio <silvioprog@gmail.com>
 *
 * This file is part of Sagui library.
 *
 * Sagui library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Sagui library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Sagui library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <stdio.h>
#include <sagui.h>

/* NOTE: Error checking has been omitted to make it clear. */

static void route_cb(void *cls, struct sg_route *route) {
    fprintf(stdout, "%s: %s\n", sg_route_path(route), (const char *) cls);
    fflush(stdout);
}

int main(void) {
    struct sg_router *router;
    struct sg_route *routes = NULL;
    sg_routes_add(&routes, "/foo", route_cb, "foo-data");
    sg_routes_add(&routes, "/bar", route_cb, "bar-data");
    router = sg_router_new(routes);
    sg_router_dispatch(router, "/foo", NULL);
    sg_routes_cleanup(&routes);
    sg_router_free(router);
    return EXIT_SUCCESS;
}
