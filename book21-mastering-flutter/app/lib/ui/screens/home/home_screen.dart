import 'package:app/ui/screens/home/home_screen_image.dart';
import 'package:app/ui/screens/home/horiz_movies.dart';
import 'package:app/ui/screens/home/title_row.dart';
import 'package:app/ui/theme/theme.dart';
import 'package:flutter/material.dart';
import 'package:flutter/foundation.dart';

class HomeScreen extends StatefulWidget {
  const HomeScreen({super.key});

  @override
  State<HomeScreen> createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  final ScrollController _scrollController = ScrollController();

  @override
  void dispose() {
    _scrollController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    final isDesktop =
        !kIsWeb &&
        (defaultTargetPlatform == TargetPlatform.macOS ||
            defaultTargetPlatform == TargetPlatform.windows ||
            defaultTargetPlatform == TargetPlatform.linux);

    return SafeArea(
      child: Scaffold(
        body: Scrollbar(
          controller: _scrollController,
          thumbVisibility: isDesktop,
          thickness: 8.0,
          radius: const Radius.circular(8.0),
          child: SingleChildScrollView(
            controller: _scrollController,
            child: Container(
              color: screenBackground,
              child: Column(
                children: [
                  Align(
                    alignment: Alignment.center,
                    child: Padding(
                      padding: const EdgeInsets.fromLTRB(0, 16.0, 0, 24),
                      child: Text('Now Playing', style: largeTitle),
                    ),
                  ),
                  HomeScreenImage(),
                  TitleRow(text: 'Trending', onMoreClicked: () {}),
                  const HorizontalMovies(),
                ],
              ),
            ),
          ),
        ),
      ),
    );
  }
}
