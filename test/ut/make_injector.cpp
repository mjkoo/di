//
// Copyright (c) 2014 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include <type_traits>
#include "boost/di/make_injector.hpp"
#include "boost/di/core/dependency.hpp"

namespace boost { namespace di {

test make_injector_types = [] {
    using dep1 = core::dependency<scopes::deduce, int>;
    using dep2 = core::dependency<scopes::deduce, double>;
    struct config { };
    expect(std::is_same<detail::injector<::BOOST_DI_CFG>, decltype(make_injector())>{});
    expect(std::is_same<detail::injector<::BOOST_DI_CFG, dep1, dep2>, decltype(make_injector(dep1{}, dep2{}))>{});
    expect(std::is_same<detail::injector<config, dep1, dep2>, decltype(make_injector<config>(dep1{}, dep2{}))>{});
};

}} // boost::di

